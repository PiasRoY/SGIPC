#include <bits/stdc++.h>
using namespace std;

#define MX 100005
#define pb push_back
vector <int> adj[MX], s;
int vis[MX], dfsno[MX], low[MX], root[MX], ans[MX], counter, scc;
void tarjan(int u)
{
	vis[u] = true;
	dfsno[u] = low[u] = counter++;
	s.pb(u);

	for(int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];

		if(dfsno[v] == -1)
			tarjan(v);
		if(vis[v])
			low[u] = min(low[u], low[v]);
	}

	if(dfsno[u] == low[u]) {
		ans[u] = 1;
		while(true) {
			int v = s.back();
			s.pop_back();
			root[v] = u;
			vis[v] = 0;
			if(u == v) break;
		}
	}
}

void reset()
{
	s.clear();
	counter = scc = 0;
	for(int i = 0; i < MX; i++) {
		adj[i].clear();
		ans[i] = vis[i] = false, dfsno[i] = -1;
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int test;
	scanf("%d", &test);

	int n, m, x, y;
	while(test--) {
		reset();
		scanf("%d %d", &n, &m);

		for(int i = 0; i < m; i++) {
			scanf("%d %d", &x, &y);
			adj[x].pb(y);
		}

		for(int i = 1; i <= n; i++)
			if(dfsno[i] == -1)
				tarjan(i);

		for(int i = 1; i <= n; i++) {
			for(int j = 0; j < adj[i].size(); j++) {
				int v = adj[i][j];
				if(root[i] != root[v])
					ans[root[v]] = false;
			}
		}

		for(int i = 1; i <= n; i++)
			if(ans[i])
				scc++;

		printf("%d\n", scc);
	}
}
