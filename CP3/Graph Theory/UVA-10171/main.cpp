#include <bits/stdc++.h>
using namespace std;

#define MX 105
#define inf 1e9
int g1[MX][MX];

void reset()
{
	for(int i = 0; i < MX; i++)
		for(int j = 0; j < MX; j++)
			g1[i][j] = inf;
}

int main()
{
	int test, n, e, x, y;

	scanf("%d", &test);
	for(int t = 1; t <= test; t++) {
		reset();

		scanf("%d %d", &n, &e);

		for(int i = 0; i < e; i++) {
			scanf("%d %d", &x, &y);
			g1[x][y] = g1[y][x] = 1;
		}

		scanf("%d %d", &x, &y);

		g1[x][x] = g1[y][y] = 0;

		for(int k = 0; k < n; k++) {
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					g1[i][j] = min(g1[i][j], g1[i][k]+g1[k][j]);
				}
			}
		}

		int mx = 0;
		for(int i = 0; i < n; i++) {
			mx = max(mx, g1[x][i]+g1[i][y]);
		}

		printf("Case %d: %d\n", t, mx);
	}
}
