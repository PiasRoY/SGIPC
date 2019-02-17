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
int dist[MX], lift[MX];
vector <int> ground;
vector <pair<pair<int, int>, int> > adj[MX];

void djk(int srcx, int lft)
{
	fill(vis, vis+MX, false);

	priority_queue <pair<int, pii>, vector <pair<int, pii> >, greater <pair<int, pii> > > pq;
	pq.push(mp(0, mp(srcx, lft)));
	dist[srcx] = 0;

	while(!pq.empty()) {
		auto u = pq.top();
		pq.pop();

		if(vis[u.ss.ff]) continue;

		vis[u.ss.ff] = true;
		for(int i = 0; i < adj[u.ss.ff].size(); i++) {
			auto tx = adj[u.ss.ff][i];

			if(u.ss.ss == tx.ff.ss && dist[tx.ff.ff] > dist[u.ss.ff] + tx.ss) {
				dist[tx.ff.ff] = dist[u.ss.ff] + tx.ss;
				pq.push(mp(dist[tx.ff.ff], mp(tx.ff.ff, tx.ff.ss)));
			}
			else if(u.ss.ss != tx.ff.ss && dist[tx.ff.ff] > dist[u.ss.ff] + tx.ss + 60) {
				dist[tx.ff.ff] = dist[u.ss.ff] + tx.ss + 60;
				pq.push(mp(dist[tx.ff.ff], mp(tx.ff.ff, tx.ff.ss)));
			}
		}
	}
}

void reset()
{
	ground.clear();
	for(int i = 0; i < MX; i++)
		adj[i].clear();
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n, flor, u, v, w;
	while(scanf("%d %d", &n, &flor) != EOF) {
		reset();

		for(int i = 0; i < n; i++)
			scanf("%d", &lift[i]);

		string str;
		stringstream ss;
		cin.ignore();
		for(int line = 0; line < n; line++) {
			getline(cin, str);

			ss << str;

			vector <int> temp;
			ss >> v; temp.pb(v);
			if(v == 0) ground.pb(line);

			while(ss>>v) {
				int l = temp.size(), tim;
				for(int i = 0; i < l; i++) {
					tim = lift[line] * (v-temp[i]);
//					cout<<temp[i]<<" "<<v<<" "<<line<<" "<<tim<<endl;
					adj[temp[i]].pb(mp(mp(v, line), tim));
					adj[v].pb(mp(mp(temp[i], line), tim));
				}
				temp.pb(v);
			}
			ss.clear();
		}

		fill(dist, dist+MX, inf);
		for(int i = 0; i < ground.size(); i++) {
			djk(0, ground[i]);
		}

		if(dist[flor] == inf) printf("IMPOSSIBLE\n");
		else printf("%d\n", dist[flor]);
	}
}
