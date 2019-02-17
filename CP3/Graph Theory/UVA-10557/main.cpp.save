#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MX 105
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define inf 1e9

int dist[MX], cost[MX], n;
vector <pair<int, int> > edgelist;

bool bellmanford(ll src)
{
	bool update = false;
	for(int i = 0; i < MX; i++) dist[i] = -inf;

	dist[src] = 100;
	for(int k = 1; k < n; k++) {
		update = false;
		for(int i = 0; i < edgelist.size(); i++) {
			auto f = edgelist[i];

			//maximum path
			int relax = dist[f.ff] + cost[f.ss];
			if(relax > 0 && dist[f.ss] < relax) {
				update = true;
				dist[f.ss] = relax;
			}
		}

		if(!update) break;
	}

	//positive cycle
	for(int i = 0; i < edgelist.size(); i++) {
		auto f = edgelist[i];

		int relax = dist[f.ff] + cost[f.ss];
		if(relax > 0 && dist[f.ss] < relax) {
			dist[f.ss] = inf;
		}
	}

	for(int k = 1; k < n; k++) {
		update = false;
		for(int i = 0; i < edgelist.size(); i++) {
			auto f = edgelist[i];

			//maximum path
			int relax = dist[f.ff] + cost[f.ss];
			if(relax > 0 && dist[f.ss] < relax) {
				update = true;
				dist[f.ss] = relax;
			}
		}

		if(!update) break;
	}

	return (dist[n] > 0);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int x, y;
	while(scanf("%d", &n) && n != -1) {
		for(int i = 1; i <= n; i++) {
			scanf("%d %d", &cost[i], &x);
			for(int j = 0; j < x; j++) {
				scanf("%d", &y);

				edgelist.pb(mp(i, y));
			}
		}

		if(bellmanford(1)) printf("winnable\n");
		else printf("hopeless\n");
		//clearing
		edgelist.clear();
	}
}
