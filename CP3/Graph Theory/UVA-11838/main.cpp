#include <bits/stdc++.h>
using namespace std;

#define MX 2005
#define pb push_back
vector <int> adj[MX], s;
int counter, scc, low[MX], dfsno[MX], vis[MX];
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
		while(true) {
			int v = s.back();
			vis[v] = false;
			s.pop_back();
			if(v == u) break;
		}
		scc++;
	}
}

void reset()
{
	s.clear();
	counter = scc = 0;
	for(int i = 0; i < MX; i++) {
		adj[i].clear();
		vis[i] = 0, dfsno[i] = -1;
	}
}

int main()
{
	int n, m, x, y, p;
	while(scanf("%d %d", &n, &m) && n+m) {
		reset();

		for(int i = 0; i < m; i++) {
			scanf("%d %d %d", &x, &y, &p);
			adj[x].pb(y);
			if(p==2) adj[y].pb(x);
		}

		for(int i = 1; i <= n; i++)
			if(dfsno[i] == -1)
				tarjan(i);

		if(scc == 1) printf("1\n");
		else printf("0\n");
	}
}
