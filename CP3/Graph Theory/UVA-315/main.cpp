#include <bits/stdc++.h>
using namespace std;

#define MX 105
#define pb push_back
bool vis[MX], articulationpoint[MX];
int root, rootch, counter, parent[MX], low[MX], dfsno[MX];
vector <int> adj[MX];
void dfs(int u)
{
	vis[u] = true, low[u] = dfsno[u] = counter++;
	for(int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];

		if(!vis[v]) {
			parent[v] = u;
			if(u == root) rootch++;

			dfs(v);

			if(low[v] >= dfsno[u]) articulationpoint[u] = true;
			low[u] = min(low[u], low[v]); // here minimum between low & low
		}
		else if(parent[u] != v) {
			low[u] = min(low[u], dfsno[v]); //here minimum between dfsno & low
		}
	}
}

void reset()
{
	counter = 0;
	for(int i = 0; i < MX; i++) {
		articulationpoint[i] = vis[i] = 0;
		adj[i].clear();
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int v;
	string line;
	while(scanf("%d", &v) && v) {
		cin.ignore();

 		reset();
		while(getline(cin, line) && line[0] != '0') {
			stringstream ss;
			ss << line;
			int x, y;
			ss >> x;
			while(ss >> y) adj[x].pb(y), adj[y].pb(x);
		}

 		for(int i = 1; i <= v; i++)
			if(!vis[i]) {
				rootch = 0, root = i;
				dfs(i);
				articulationpoint[root] = (rootch>1);
			}

		int cnt = 0;
		for(int i = 1; i <= v; i++) {
			if(articulationpoint[i]) cnt++;
		}
		printf("%d\n", cnt);
	}
}

/*
5
1 2 3
2 3 4 5
4 5
0
*/
