#include <bits/stdc++.h>
using namespace std;

#define MX 10005
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
bool vis[MX];
vector <int> adj[MX];
vector <pair<int, int> > ans;
int counter, parent[MX], low[MX], dfsno[MX], articulationpoint[MX], root, rootch;
void dfs(int u)
{
	vis[u] = true, dfsno[u] = low[u] = counter++;
	for(int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];

		if(!vis[v]) {
			if(u == root) rootch++;
			parent[v] = u;
			dfs(v);

			if(low[v] >= dfsno[u]) articulationpoint[u]++;
			low[u] = min(low[u], low[v]);
		}
		else if(parent[u] != v)
			low[u] = min(low[u], dfsno[v]);
	}
}

#define pii pair<int, int>
bool cmp(pii a, pii b)
{
	if(a.ss > b.ss) return true;
	else if(a.ss == b.ss) {
		if(a.ff < b.ff) return true;
	}
	return false;
}

void reset()
{
	counter = 0;
	ans.clear();
	for(int i = 0; i < MX; i++) {
		adj[i].clear();
		vis[i] = articulationpoint[i] = 0;
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n, m, x, y;
	while(scanf("%d %d", &n, &m) && n+m) {
		while(scanf("%d %d", &x, &y) && (x+y != -2)) {
			adj[x].pb(y);
			adj[y].pb(x);
		}

		for(int i = 0; i < n; i++)
			if(!vis[i]) {
				root = i, rootch = 0;
				dfs(i);

				articulationpoint[root] = (rootch>1)?rootch-1:0;
			}

		for(int i = 0; i < n; i++) {
			ans.pb(mp(i, articulationpoint[i]+1));
		}

		sort(ans.begin(), ans.end(), cmp);
		for(int i = 0; i < m; i++)
			printf("%d %d\n", ans[i].ff, ans[i].ss);
		printf("\n");
		reset();
	}
}
