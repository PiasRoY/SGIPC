#include <bits/stdc++.h>
using namespace std;

#define MX 105
#define ff first
#define ss second
#define pb push_back
int mn, parent[MX];
bool vis[MX];
vector <pair<int, int> > adj[MX];
void dfs(int u, int cst)
{
	vis[u] = true;
	for(int i = 0; i < adj[u].size(); i++) {
		auto v = adj[u][i];

		if(!vis[v.ff]) {
			parent[v.ff] = u;
			dfs(v.ff, cst+v.ss);
		}
		else if(parent[u] != v.ff && v.ff == 1) {
			mn = min(mn, cst+v.ss);
		}
	}
	vis[u] = false;
}

void reset()
{
	for(int i = 0; i < MX; i++) {
		vis[i] = false, adj[i].clear();
	}
}

int main()
{
	int test;
	scanf("%d", &test);

	int n, x, y, w;
	for(int t = 1; t <= test; t++) {
		reset();
		scanf("%d", &n);

		for(int i = 0; i < n; i++) {
			scanf("%d %d %d", &x, &y, &w);
			adj[x].pb({y, 0});
			adj[y].pb({x, w});
		}

		mn = INT_MAX;
		dfs(1, 0);
		printf("Case %d: %d\n", t, mn);
	}
}
