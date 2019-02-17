#include <bits/stdc++.h>
using namespace std;

#define MX 3000
#define inf 1e9
#define pb push_back
#define mp make_pair

vector <int> adj[MX];
int dist[MX], n, M, D;

void bfs(int src)
{
	fill(dist, dist+MX, inf);
	queue <int> q;

	q.push(src);
	dist[src] = M = D = 0;

	while(!q.empty()) {
		int u = q.front();
		q.pop();

		for(int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i];

			if(dist[v] == inf) {
				q.push(v);
				dist[v] = dist[u] + 1;
			}
		}

		if((q.size() > M) && (dist[q.front()] == dist[u]+1)) {
			M = q.size();
			D = dist[u]+1;
		}
	}
}

void reset()
{
	for(int i = 0; i < n; i++)
		adj[i].clear();
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int u, v, test;
	while(scanf("%d", &n) != EOF) {
		reset();

		for(int j = 0; j < n; j++) {
			scanf("%d", &u);
			for(int i = 0; i < u; i++) {
				scanf("%d", &v);
				adj[j].pb(v);
			}
		}

		scanf("%d", &test);
		for(int t = 1; t <= test; t++) {
			scanf("%d", &u);
			bfs(u);

			if(M == 0) printf("0\n");
			else printf("%d %d\n", M, D);
		}
	}
}
