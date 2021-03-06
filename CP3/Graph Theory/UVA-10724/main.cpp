#include <bits/stdc++.h>
using namespace std;

#define MX 55
#define inf 1e9
#define ff first
#define ss second
#define pii pair <int, int>
double g[MX][MX];
pii point[MX];

double dis(pii a, pii b)
{
	double x = a.ff-b.ff, y = a.ss-b.ss;
	return sqrt(x*x + y*y);
}

void reset()
{
	for(int i = 0; i < MX; i++)
		for(int j = 0; j < MX; j++)
			if(i == j) g[i][j] = 0;
			else g[i][j] = inf;
}

int main()
{
	int n, m, x, y;
	while(scanf("%d %d", &n, &m) && n+m) {

		for(int i = 1; i <= n; i++) {
			scanf("%d %d", &point[i].ff, &point[i].ss);
		}

		reset();
		for(int j = 1; j <= m; j++) {
			scanf("%d %d", &x, &y);
			g[x][y] = g[y][x] = dis(point[x], point[y]);
		}

		//floydwarshall
		for(int k = 1; k <= n; k++) {
			for(int i = 1; i <= n; i++) {
				for(int j = 1; j <= n; j++) {
					g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
				}
			}
		}

		//solve
		double sum, d, mx = 0;
		for(int _i = 1; _i <= n; _i++) {
			for(int _j = 1; _j <= n; _j++) {

				if(g[_i][_j] == inf) continue;

				sum = 0, d = dis(point[_i], point[_j]);
				for(int i = 1; i <= n; i++) {
					for(int j = 1; j <= n; j++) {
						sum += g[i][j] - min(g[i][j], min(g[i][_i]+d+g[_j][j], g[i][_j]+d+g[_i][j]));
					}
				}

				if(sum > mx) {
					mx = sum;
					x = _i, y = _j;
				}
			}
		}

		if(mx == 0) printf("No road required\n");
		else printf("%d %d\n", x, y);
	}
}
