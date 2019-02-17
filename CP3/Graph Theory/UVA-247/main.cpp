#include <bits/stdc++.h>
using namespace std;

#define MX 30
#define pb push_back
bool vis[MX];
map <string, int> mp1;
map <int, string> mp2;
vector <int> adj[MX], s, ans[MX];
int counter, numSCC, low[MX], dfsno[MX];

void tarjanSCC(int u)
{
	vis[u] = true;
	dfsno[u] = low[u] = counter++;
	s.pb(u);

	for(int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];

		if(dfsno[v] == -1)
			tarjanSCC(v);
		if(vis[v])
			low[u] = min(low[u], low[v]);
	}

	if(dfsno[u] == low[u]) {
		while(true) {
			int v = s.back();
			s.pop_back();
			vis[v] = false;
			ans[numSCC].pb(v);
			if(v == u) break;
		}
		numSCC++;
	}
}

int k;
void reset()
{
	s.clear(); mp1.clear(), mp2.clear();
	k = numSCC = counter = 0;
	for(int i = 0; i < MX; i++) {
		adj[i].clear();
		ans[i].clear();
		dfsno[i] = -1;
		vis[i] = false;
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n, m, test = 1;
	string s, t;
	while(scanf("%d %d", &n, &m) && n+m) {
		reset();
		for(int i = 0; i < m; i++) {
			cin>>s>>t;

			if(mp1.find(s) == mp1.end()) mp1[s] = k, mp2[k++] = s;
			if(mp1.find(t) == mp1.end()) mp1[t] = k, mp2[k++] = t;
			adj[mp1[s]].pb(mp1[t]);
//			cout<<mp1[s]<<" "<<mp1[t]<<endl;
		}

		for(int i = 0; i < k; i++)
			if(dfsno[i] == -1)
				tarjanSCC(i);

		printf("Calling circles for data set %d:\n", test++);
		for(int i = 0; i < numSCC; i++) {
			cout<<mp2[ans[i][0]];
			for(int j = 1; j < ans[i].size(); j++) {
				cout<<", "<<mp2[ans[i][j]];
			}
			printf("\n");
		}
	}
}
