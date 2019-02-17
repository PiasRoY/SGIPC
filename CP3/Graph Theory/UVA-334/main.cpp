#include <bits/stdc++.h>
using namespace std;

#define MX 205
#define inf 1e9

bool conct[MX][MX];

void floyd(int n)
{
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				conct[i][j] |= (conct[i][k] & conct[k][j]);
			}
		}
	}
}

int n, m, k;
string s, previ;
map <string, int> mp1;
map <int, string> mp2;

void reset()
{
	k = 1;
	mp1.clear(), mp2.clear();
	for(int i = 0; i < MX; i++) {
		for(int j = 0; j < MX; j++) {
			if(i == j) conct[i][i] = true;
			else conct[i][j] = false;
		}
	}
}

int main()
{
	int test = 1;
	while(scanf("%d", &n) && n != 0) {
		reset();

		for(int i = 0; i < n; i++) {
			scanf("%d", &m);

			cin>>previ;
			mp2[k] = previ;
			mp1[previ] = k++;

			for(int i = 1; i < m; i++) {
				cin>>s;

				if(mp1.find(s) == mp1.end()) {
					mp2[k] = s;
					mp1[s] = k++;
				}

				conct[mp1[previ]][k-1] = true;

				previ = s;
			}
		}

		scanf("%d", &m);
		for(int i = 0; i < m; i++) {
			cin>>previ>>s;

			conct[mp1[previ]][mp1[s]] = true;
		}

		floyd(k-1);

		int cnt = 0;
		set <pair<int, int> > st;
		for(int i = 1; i < k; i++) {
			for(int j = 1; j < k; j++) {
				if(!conct[i][j] && !conct[j][i]) {
					cnt++;
					st.insert(make_pair(min(i, j), max(i, j)));
				}
			}
		}

		cnt /= 2;
		if(cnt == 0) printf("Case %d, no concurrent events.\n", test++);
		else {
			printf("Case %d, %d concurrent events:\n", test++, cnt);

			int l = st.size(); l = min(l, 2);
			for(auto it = st.begin();  l != 0; it++, l--) {
				cout<<"("<<mp2[it->first]<<","<<mp2[it->second]<<") ";
			}
			printf("\n");
		}
	}
}
