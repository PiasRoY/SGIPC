#include <bits/stdc++.h>
using namespace std;

#define MX 305
#define pb push_back
bool vis[MX], color[MX];
vector <int> adj[MX];
bool tf;
void dfs(int x)
{
	vis[x] = true;
	for(int i = 0; tf && i < adj[x].size(); i++) {
		int y = adj[x][i];

		if(!vis[y]) color[y] = 1-color[x], dfs(y);
		else if(color[y] == color[x]) {
			tf = false;
			return;
		}
	}
}

int main()
{
	int v;
	while(scanf("%d", &v) && v) {
		int x, y;
		while(scanf("%d %d", &x, &y) && x+y) {
			adj[x].pb(y);
			adj[y].pb(x);
		}

		tf = true;
		for(int i = 1; i <= v; i++)
			if(tf && !vis[i])
				dfs(i);

		if(tf) printf("YES\n");
		else printf("NO\n");

		//clearing
		for(int i = 0; i <= v; i++)
			vis[i] = false, adj[i].clear();
	}
}

/*
6
1 4
1 2
1 3
4 5
4 6
2 5
2 6
3 5
3 6
0 0
*/
