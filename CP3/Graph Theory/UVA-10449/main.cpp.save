#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MX 205
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define inf 100000000000

ll dist[MX];
int busy[MX], n;
vector <pair<pair<int, int>, int> > edgelist;

void bellmanford(ll src)
{
	bool update, negcycle = false;
	fill(dist, dist+MX, inf);

	dist[src] = 0;
	for(int k = 1; k <= n; k++) {
		update = false;
		for(int i = 0; i < edgelist.size(); i++) {
			auto f = edgelist[i];

			if(dist[f.ff.ff] == inf) continue;
			if(dist[f.ff.ss] > dist[f.ff.ff] + f.ss) {
				update = true;
				dist[f.ff.ss] = dist[f.ff.ff] + f.ss;
			}
		}

		if(k == n && update) negcycle = true;
		else if(!update) break;
	}

	if(negcycle) {
		for(int i = 0; i < edgelist.size(); i++) {
			auto f = edgelist[i];

			if(dist[f.ff.ff] == inf) continue;
			if(dist[f.ff.ss] > dist[f.ff.ff] + f.ss) {
				update = true;
				dist[f.ff.ss] = -inf;
			}
		}
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int test = 0, x, y, w, r, q;

	while(scanf("%d", &n) == 1) {
		for(int i = 1; i <= n; i++) {
			scanf("%d", &busy[i]);
		}

		scanf("%d", &r);

		edgelist.clear();
		for(int i = 0; i < r; i++) {
			scanf("%d %d", &x, &y);

			w = (busy[y]-busy[x]);
			w = w*w*w;

			edgelist.pb(mp(mp(x, y), w));
		}

		bellmanford(1);

		scanf("%d", &q);
		printf("Set #%d\n", ++test);
		while(q--) {
			scanf("%d", &x);

			if(dist[x] < 3 || dist[x] == inf) printf("?\n");
			else printf("%lld\n", dist[x]);
		}
	}
}
