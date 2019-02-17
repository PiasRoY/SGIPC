#include <bits/stdc++.h>
using namespace std;

#define MX 55
#define mp make_pair
#define ff first
#define ss second
int n, m;
bool vis[MX][MX][4];
int grid[MX][MX];
int dist[MX][MX][4];

int d1[] = {-1, 0, 1, 0};
int d2[] = {0, 1, 0, -1};

void bfs(int dir, int srcx, int srcy)
{
	memset(vis, 0, sizeof vis);
	queue <pair<int, pair<int, int> > > q;

	q.push(mp(dir, mp(srcx, srcy)));
	vis[srcx][srcy][dir] = true;
	dist[srcx][srcy][dir] = 0;

	while(!q.empty()) {
		auto f = q.front();
		q.pop();

		//turn
		int D1 = (f.ff + 1 + 4) % 4; //right
		int D2 = (f.ff - 1 + 4) % 4; //left

		int tx = f.ss.ff, ty = f.ss.ss;

		if(!vis[tx][ty][D1]) {
			q.push(mp(D1, mp(f.ss.ff, f.ss.ss)));
			vis[tx][ty][D1] = true;
			dist[tx][ty][D1] = dist[f.ss.ff][f.ss.ss][f.ff] + 1;
		}

		if(!vis[tx][ty][D2]) {
			q.push(mp(D2, mp(f.ss.ff, f.ss.ss)));
			vis[tx][ty][D2] = true;
			dist[tx][ty][D2] = dist[f.ss.ff][f.ss.ss][f.ff] + 1;
		}

		//go
		for(int i = 0; i < 3; i++) {
			tx += d1[f.ff], ty += d2[f.ff];

			if(grid[tx][ty] || grid[tx-1][ty] || grid[tx][ty-1] || grid[tx-1][ty-1])
				break;

			if(!vis[tx][ty][f.ff] && tx > 0 && tx < n && ty > 0 && ty < m)
			{
				q.push(mp(f.ff, mp(tx, ty)));
				vis[tx][ty][f.ff] = true;
				dist[tx][ty][f.ff] = dist[f.ss.ff][f.ss.ss][f.ff] + 1;
			}
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	while(scanf("%d %d", &n, &m) && n+m) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				scanf("%d", &grid[i][j]);
			}
		}

		int srcx, srcy, desx, desy;
		scanf("%d %d %d %d", &srcx, &srcy, &desx, &desy);

		string s;
		cin>>s;

		int d;
		if(s == "north") d = 0;
		else if(s == "east") d = 1;
		else if(s == "south") d = 2;
		else if(s == "west") d = 3;

		if(!grid[srcx][srcy] && !grid[srcx-1][srcy] && !grid[srcx][srcy-1] && !grid[srcx-1][srcy-1])
			bfs(d, srcx, srcy);

		if(vis[desx][desy][0] + vis[desx][desy][1] + vis[desx][desy][2] + vis[desx][desy][3] == 0)
			printf("-1\n");
		else {
			int mn = INT_MAX;
			for(int i = 0; i < 4; i++) {
				if(vis[desx][desy][i]) {
					mn = min(mn, dist[desx][desy][i]);
				}
			}
			printf("%d\n", mn);
		}
	}
}

// Udebug hints are very useful for this problem.
