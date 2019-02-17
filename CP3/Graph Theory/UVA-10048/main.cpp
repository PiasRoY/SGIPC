#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MX 200005
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>
ll mst;
int parent[MX], n, m;
vector <pii> adj[MX];
vector <pair<int, pii> > edgelist;
int find(int u)
{
	if(u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

void kruskal()
{
	for(int i = 0; i < MX; i++) parent[i] = i;
	sort(edgelist.begin(), edgelist.end());

	int cnt = 0;
	mst = 0;
	for(int i = 0; i < edgelist.size(); i++) {
		auto u = edgelist[i];
		int pu = find(u.ss.ff);
		int pv = find(u.ss.ss);

		if(pu != pv) {
			parent[pu] = pv;
			adj[u.ss.ff].pb(mp(u.ss.ss, u.ff));
			adj[u.ss.ss].pb(mp(u.ss.ff, u.ff));
			if(++cnt == n-1) break;
		}
	}
}

bool vis[MX], tf;
void dfs(int u, int v, int mx)
{
	if(u == v) {
		tf = true;
		printf("%d\n", mx);
		return;
	}

	vis[u] = true;
	for(int i = 0; i < adj[u].size(); i++) {
		if(!vis[adj[u][i].ff])
			dfs(adj[u][i].ff, v, max(mx, adj[u][i].ss));
	}
	vis[u] = false;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int test = 1, x, y, w, q;
	long long sum;
	while(scanf("%d %d %d", &n, &m, &q) && n+m+q) {
		for(int i = 0; i < m; i++) {
			scanf("%d %d %d", &x, &y, &w);
			edgelist.pb(mp(w, mp(x, y)));
		}

		kruskal();

		if(test != 1) printf("\n");
		printf("Case #%d\n", test++);
		while(q--) {
			tf = false;
			scanf("%d %d", &x, &y);
			dfs(x, y, 0);
			if(!tf) printf("no path\n");
		}

		//clearing
		edgelist.clear();
		for(int i = 0; i < MX; i++)
			adj[i].clear();
	}
}
