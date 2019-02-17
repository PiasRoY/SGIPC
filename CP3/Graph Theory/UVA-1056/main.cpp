#include <bits/stdc++.h>
using namespace std;

#define MX 100
#define inf 1e9
bool vis[MX];
int mat[MX][MX], k;
map <string, int> mp1;

void reset()
{
	mp1.clear(); k = 0;
	for(int i = 0; i < MX; i++) {
		vis[i] = false;
		for(int j = 0; j < MX; j++) {
			if(i == j) mat[i][j] = 0;
			else mat[i][j] = inf;
		}
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	string s, t;
	int n, m, x, y, test = 1;
	while(scanf("%d %d", &n, &m) && n+m) {
		reset();

		for(int i = 0; i < m; i++) {
			cin>>s>>t;

			if(mp1.find(s) == mp1.end()) mp1[s] = k++;
			if(mp1.find(t) == mp1.end()) mp1[t] = k++;

			x = mp1[s], y = mp1[t];

			mat[x][y] = 1;
			mat[y][x] = 1;
		}

		//floydwarshall
		for(k = 0; k < n; k++) {
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
				}
			}
		}

		int diameter = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				diameter = max(diameter, mat[i][j]);
			}
		}

		if(diameter == inf) printf("Network %d: DISCONNECTED\n\n", test++);
		else printf("Network %d: %d\n\n", test++, diameter);
	}
}
