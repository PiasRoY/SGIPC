#include <bits/stdc++.h>
using namespace std;

#define MX 205
#define pb push_back
int o, z;
vector <int> adj[MX];
bool tf, vis[MX], color[MX];
void dfs(int u)
{
	vis[u] = true;
	for(int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];

		if(!vis[v]) {
			color[v] = 1-color[u];
			if(color[v]) o++;
			else z++;
			dfs(v);
		}
		else if(color[u] == color[v]) {
			tf = false;
		}
	}
}

void reset()
{
	for(int i = 0; i < MX; i++) {
		vis[i] = color[i] = false;
		adj[i].clear();
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int test;
	scanf("%d", &test);

	int n, m, x;
	for(int t = 1; t <= test; t++) {
		reset();
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			scanf("%d", &m);
			for(int j = 0; j < m; j++) {
				scanf("%d", &x);
				if(x > n) continue;
				adj[i].pb(x);
				adj[x].pb(i);
			}
		}

		int cnt = 0;
		for(int i = 1; i <= n; i++) {
			if(!vis[i]) {
				tf = true, o = 0, z = 1;
				dfs(i);
				if(tf) cnt += max(o, z);
				if(o == 0 && z == 0) cnt++;
			}
		}

		printf("%d\n", cnt);
	}
}
