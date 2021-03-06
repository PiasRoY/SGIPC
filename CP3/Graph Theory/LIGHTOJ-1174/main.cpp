#include <bits/stdc++.h>
using namespace std;

#define MX 105
#define pb push_back
int sdist[MX], ddist[MX], vis[MX];
vector <int> adj[MX];
void bfs(int src, int* dist)
{
	queue <int> q;
	q.push(src);
	vis[src] = true;
	dist[src] = 0;

	while(!q.empty())
	{
		int u = q.front();
		q.pop();

		for(int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i];

			if(!vis[v]) {
				q.push(v);
				vis[v] = true;
				dist[v] = dist[u] + 1;
			}
		}
	}
}

void reset()
{
	for(int i = 0; i < MX; i++) {
		adj[i].clear();
		vis[i] = false;
	}
}

int main()
{
	int test;
	scanf("%d", &test);

	int n, m, x, y, src, des;
	for(int t = 1; t <= test; t++) {
		reset();
		scanf("%d %d", &n, &m);

		for(int i = 0; i < m; i++) {
			scanf("%d %d", &x, &y);
			adj[x].pb(y);
			adj[y].pb(x);
		}

		scanf("%d %d", &src, &des);
		bfs(src, sdist);

		memset(vis, false, sizeof vis);
		bfs(des, ddist);

		int mx = 0;
		for(int i = 0; i < n; i++) {
			mx = max(mx, sdist[i]+ddist[i]);
		}

		printf("Case %d: %d\n", t, mx);
	}
}
