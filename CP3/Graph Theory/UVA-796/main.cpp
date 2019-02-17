#include <bits/stdc++.h>
using namespace std;

#define MX 10000
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
bool vis[MX];
vector <int> adj[MX];
vector <pair<int, int> > ans;
int v, e, x, y, counter, parent[MX], low[MX], dfsno[MX];
void dfs(int u)
{
	vis[u] = true, low[u] = dfsno[u] = counter++;
	for(int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];

		if(!vis[v]) {
			parent[v] = u;
			dfs(v);

			if(low[v] > dfsno[u]) ans.pb(mp(min(u, v), max(u, v)));
			low[u] = min(low[u], low[v]);
		}
		else if(parent[u] != v) low[u] = min(low[u], dfsno[v]);
	}
}

void reset()
{
	counter = 0;
	ans.clear();
	for(int i = 0; i < MX; i++) {
		adj[i].clear();
		vis[i] = false;
	}
}

int main()
{
	while(scanf("%d", &v) != EOF) {
		reset();
		for(int i = 0; i < v; i++) {
			scanf("%d (%d)", &x, &e);

			while(e--) {
				scanf("%d", &y);
				adj[x].pb(y);
			}
		}

		for(int i = 0; i < v; i++)
			if(!vis[i])
				dfs(i);

		sort(ans.begin(), ans.end());
		printf("%d critical links\n", ans.size());
		for(int i = 0; i < ans.size(); i++)
			printf("%d - %d\n", ans[i].ff, ans[i].ss);
		printf("\n");
	}
}
