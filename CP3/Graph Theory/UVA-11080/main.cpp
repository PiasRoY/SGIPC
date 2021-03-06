#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define MX 205
int n, e, o, z, color[MX];
bool vis[MX], tf;
vector <int> adj[MX];
void dfs(int x)
{
	vis[x] = true;
	for(int i = 0; tf && i < adj[x].size(); i++) {
		int v = adj[x][i];

		if(!vis[v]) {
			color[v] = 1-color[x];
			if(color[v] == 0) z++;
			else o++;
			dfs(v);
		}
		else if(color[v] == color[x]) {
			tf = false;
			return;
		}
	}
}

void reset()
{
	memset(vis, false, sizeof vis);
	for(int i = 0; i < MX; i++)
		adj[i].clear();
}

int main()
{
	int test;
	scanf("%d", &test);

	while(test--) {
		reset();
		scanf("%d %d", &n, &e);

		int x, y;
		for(int i = 0; i < e; i++) {
			scanf("%d %d", &x, &y);
			adj[x].pb(y);
			adj[y].pb(x);
		}

		int total = 0;
		tf = true;
		for(int i = 0; i < n; i++) {
			if(!vis[i]) {
				o = 0, z = 1;
				color[i] = 0;
				dfs(i);
				if(!tf) break;
				if(o == 0 || z == 0) total += max(o, z);
				else total += min(o, z);
			}
		}

		if(!tf) printf("-1\n");
		else printf("%d\n", total);
	}
}
