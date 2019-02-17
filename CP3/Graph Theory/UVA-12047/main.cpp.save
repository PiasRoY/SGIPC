#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MX 10005
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define inf 100000000
#define pll pair<ll, ll>

bool vis[MX];
ll sdist[MX], ddist[MX];
vector <pair<ll, ll> > s_adj[MX], rev_adj[MX];

void djk(ll src, ll* dist, vector <pll>* adj)
{
	fill(vis, vis+MX, false);
	fill(dist, dist+MX, inf);

	priority_queue <pll, vector<pll>, greater<pll> > pq;
	pq.push(mp(0, src));
	dist[src] = 0;

	while(!pq.empty()) {
		auto u = pq.top();
		pq.pop();

		if(vis[u.ss]) continue;

		vis[u.ss] = true;
		for(int i = 0; i < adj[u.ss].size(); i++) {
			auto v = adj[u.ss][i];

			if(dist[v.ff] > dist[u.ss] + v.ss) {
				dist[v.ff] = dist[u.ss] + v.ss;

				pq.push(mp(dist[v.ff], v.ff));
			}
		}
	}
}

void reset()
{
	for(int i = 0; i < MX; i++)
		s_adj[i].clear(), rev_adj[i].clear();
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int test;
	scanf("%d", &test);

	ll n, m, s, t, p, x, y, w;
	while(test--) {
		reset();

		scanf("%lld %lld %lld %lld %lld", &n, &m, &s, &t, &p);

		for(int i = 0; i < m; i++) {
			scanf("%lld %lld %lld", &x, &y, &w);

			s_adj[x].pb(mp(y, w));
			rev_adj[y].pb(mp(x, w));
		}

		djk(s, sdist, s_adj);
		djk(t, ddist, rev_adj);

		ll mx = -1, sum;
		for(int i = 1; i <= n; i++) {
			for(int j = 0; j < s_adj[i].size(); j++) {
				y = s_adj[i][j].ff, w = s_adj[i][j].ss;
				sum = sdist[i]+w+ddist[y];
//				cout<<i<<" "<<y<<" "<<sdist[i]<<" "<<s_adj[i][j].ss<<" "<<ddist[y]<<endl;
				if((sum <= p) && (mx < w)) {
					mx = w;
				}
			}
		}

		printf("%lld\n", mx);
	}
}
