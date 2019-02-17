#include <bits/stdc++.h>
using namespace std;

#define MX 15
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
int d1[] = {1, 1, 2, 2, -1, -1, -2, -2};
int d2[] = {2, -2, 1, -1, 2, -2, 1, -1};
bool vis[105][15][15];
int dist[105][15][15], n, m;
vector <pair<int, pair<int, int> > > riders;
void bfs(int p, int x, int y)
{
	queue <pair<int, int> > q;
	q.push(mp(x, y));
	vis[p][x][y] = true;
	dist[p][x][y] = 0;

	while(!q.empty())
	{
		auto u = q.front();
		q.pop();

		for(int i = 0; i < 8; i++) {
			auto v = mp(u.ff+d1[i], u.ss+d2[i]);

			if(v.ff < 0 || v.ff >= n || v.ss < 0 || v.ss >= m) continue;
			if(!vis[p][v.ff][v.ss]) {
				q.push(v);
				vis[p][v.ff][v.ss] = true;
				dist[p][v.ff][v.ss] = dist[p][u.ff][u.ss] + 1;
			}
		}
	}
}

int main()
{
	int test;
	scanf("%d", &test);

	char ch;
	for(int t = 1; t <= test; t++) {
		scanf("%d %d", &n, &m);

		riders.clear();
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m ;j++) {
				cin>>ch;
				if(ch >= '1' && ch <= '9') {
					riders.pb(mp((ch-'0'), mp(i, j)));
				}
			}

		memset(vis, 0, sizeof vis);
		for(int i = 0; i < riders.size(); i++) {
			bfs(i, riders[i].ss.ff, riders[i].ss.ss);
		}

		bool tf;
		int distant, mn = INT_MAX;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				tf = true, distant = 0;
				for(int k = 0; k < riders.size(); k++) {
					if(!vis[k][i][j]) {
						tf = false;
						break;
					}
					distant += ceil((dist[k][i][j]*1.0) / riders[k].ff);
				}
				if(tf) mn = min(mn, distant);
			}
		}

		if(mn == INT_MAX) printf("Case %d: -1\n", t);
		else printf("Case %d: %d\n", t, mn);
	}
}
