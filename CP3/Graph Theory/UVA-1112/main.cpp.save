#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MX 105
#define inf 10000000
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>

int n, e, T, m;
bool vis[MX];
int dist[MX];
vector <pair<int, int> > adj[MX];

void djk(int srcx)
{
	fill(dist, dist+MX, inf);
	fill(vis, vis+MX, false);

	priority_queue <pii, vector <pii>, greater <pii> > pq;

	pq.push(mp(0, srcx));
	dist[srcx] = 0;

	while(!pq.empty()) {
		auto u = pq.top();
		pq.pop();

		if(vis[u.ss]) continue;

		vis[u.ss] = true;
		for(int i = 0; i < adj[u.ss].size(); i++) {
			auto tx = adj[u.ss][i];

			if(dist[tx.ff] > dist[u.ss] + tx.ss) {
				dist[tx.ff] = dist[u.ss] + tx.ss;
				pq.push(mp(dist[tx.ff], tx.ff));
			}
		}
	}
}

void reset()
{
	for(int i = 0; i < MX; i++)
		adj[i].clear();
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int test;
	scanf("%d", &test);

	int u, v, w;
	for(int t = 1; t <= test; t++) {
		reset();

		scanf("%d %d %d %d", &n, &e, &T, &m);

		for(int  i = 0; i < m; i++) {
			scanf("%d %d %d", &u, &v, &w);
			adj[v].pb(mp(u, w));
		}

		djk(e);

		int cnt = 0;
		for(int i = 1; i <= n; i++)
			if(dist[i] <= T)
				cnt++;

		printf("%d\n", cnt);

		if(t != test) printf("\n");
	}
}
