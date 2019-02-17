#include <bits/stdc++.h>
using namespace std;

#define MX 105
#define pb push_back
bool vis[MX];
vector <int> adj[MX], ans;
void dfs(int x)
{
	vis[x] = true;
	for(int i = 0; i < adj[x].size(); i++) {
		int u = adj[x][i];
		if(!vis[u]) {
			dfs(u);
			ans.pb(u);
		}
	}
}

void reset()
{
	ans.clear();
	memset(vis, false, sizeof vis);
	for(int i = 0;i < MX; i++)
		adj[i].clear();
}

int main()
{
	int n, m, x, y;
	while(scanf("%d %d", &n, &m) && n+m) {
		reset();
		for(int i = 0; i < m; i++) {
			scanf("%d %d", &x, &y);
			adj[x].pb(y);
		}

		for(int i = 1; i <= n; i++)
			if(!vis[i])
				dfs(i), ans.pb(i);

		printf("%d", *ans.rbegin());
		for(int i = n-2; i >= 0; i--)
			printf(" %d", ans[i]);
		printf("\n");
	}
}

/*
5 4
3 1
3 2
2 1
3 5
0 0
*/
