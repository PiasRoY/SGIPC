#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MX 205
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ppii pair<int, pii>
int n, parent[MX];
vector <pii> adj[MX];
map <string, int> mp1;
vector <ppii> edgelist;

int find(int u)
{
	if(parent[u] == u) return u;
	return parent[u] = find(parent[u]);
}

bool cmp(ppii a, ppii b)
{
	if(a.ff > b.ff) return true;
	return false;
}

void kruskal()
{
	for(int i = 0; i <= n; i++) parent[i] = i;
	sort(edgelist.begin(), edgelist.end(), cmp);

	int cnt = 0;
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

int mini;
bool vis[MX];
void dfs(int x, int y, int mn)
{
	if(x == y) {
		mini = min(mn, mini);
		return;
	}

	vis[x] = true;
	for(int i = 0; i < adj[x].size(); i++) {
		pii u = adj[x][i];
		if(!vis[u.ff])
			dfs(u.ff, y, min(mn, u.ss));
	}

	vis[x] = false;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	string s, t;
	int m, x, y, w, k, test = 1;
	while(scanf("%d %d", &n, &m) && n+m) {
		k = 0;
		for(int i = 0; i < m; i++) {
			cin>>s>>t>>w;

			if(mp1.find(s) == mp1.end()) mp1[s] = k++;
			if(mp1.find(t) == mp1.end()) mp1[t] = k++;
			edgelist.pb(mp(w, mp(mp1[s], mp1[t])));
		}

		cin>>s>>t;
		kruskal();

		printf("Scenario #%d\n", test++);
		mini = INT_MAX;
		dfs(mp1[s], mp1[t], INT_MAX);
		printf("%d tons\n", mini);

		printf("\n");
		//clearing
		mp1.clear();
		edgelist.clear();
		for(int i = 0; i < MX; i++)
			adj[i].clear();

	}
}
