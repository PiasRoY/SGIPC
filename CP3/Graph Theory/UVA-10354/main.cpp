#include <bits/stdc++.h>
using namespace std;

#define MX 105
#define inf 1e9

set <int> shrt;
bool mark[MX];
int mat[MX][MX], edge[MX][MX], p;

void floyd(int dist[MX][MX])
{
	for(int k = 1; k <= p; k++) {
		if(mark[k]) continue;
		for(int i = 1; i <= p; i++) {
			if(mark[i]) continue;
			for(int j = 1; j <= p; j++) {
				if(mark[j]) continue;
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

void reset()
{
	for(int i = 0; i < MX; i++) {
		mark[i] = false;
		for(int j = 0; j < MX; j++) {
			if(i == j) mat[i][j] = edge[i][j] = 0;
			else mat[i][j] = edge[i][j] = inf;
		}
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int a, b, w, r, bh, of, yh, m;

	while(scanf("%d %d %d %d %d %d", &p, &r, &bh, &of, &yh, &m) != EOF) {
		reset();

		for(int i = 0; i < r; i++) {
			scanf("%d %d %d", &a, &b, &w);

			mat[a][b] = edge[a][b] = w;
			mat[b][a] = edge[b][a] = w;
		}

		floyd(mat);

		for(int i = 1; i <= p; i++) {
			if(mat[bh][of] == mat[bh][i] + mat[i][of]) {
				mark[i] = true;
				edge[i][i] = inf;
			}
		}

		floyd(edge);

		if(edge[yh][m] == inf || mark[yh] || mark[m])
			printf("MISSION IMPOSSIBLE.\n");
		else
			printf("%d\n", edge[yh][m]);
	}
}
