#include <cstdlib>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define MX 205
vector <int> adj[MX];
int color[MX], vis[MX];
bool bipartitable(int src)
{
	memset(color, -1, sizeof color);
	memset(vis, 0, sizeof vis);
	queue <int> q;

	q.push(src);
	color[src] = 0;

	bool tf = true;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();

		vis[u] = 1;
		for(int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i];

			if(vis[v]) continue;
			if(color[v] == -1) {
				color[v] = 1-color[u];
			}
			else if(color[u] == color[v]) {
				tf = false;
				break;
			}
			q.push(v);
		}
	}

	return tf;
}

int main()
{
	int n, e, x, y;

	while(scanf("%d", &n) && n) {
		scanf("%d", &e);
		for(int i = 0; i < e; i++) {
			scanf("%d %d", &x, &y);

			adj[x].push_back(y);
			adj[y].push_back(x);
		}

		bool tf = bipartitable(0);
		if(tf) printf("BICOLORABLE.\n");
		else printf("NOT BICOLORABLE.\n");

		//clearing
		for(int i = 0; i < n; i++)
			adj[i].clear();
	}
}
