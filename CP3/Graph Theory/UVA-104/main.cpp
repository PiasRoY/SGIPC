#include <bits/stdc++.h>
using namespace std;

#define MX 25

int n;
double table[MX][MX][MX], path[MX][MX][MX];

void printpath(int step, int u, int v)
{
	if(step != 1) printpath(step-1, u, path[step-1][u][v]);
	printf("%d ", v);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	while(scanf("%d", &n) != EOF) {
		memset(table, 0, sizeof table);

		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				path[1][i][j] = i;

				if(i == j)
					table[1][i][j] = 1.0;
				else
					scanf("%lf", &table[1][i][j]);
			}
		}

		bool tf = false;
		int step, i, j, k;
		for(step = 2; step <= n && !tf; step++) {
			for(k = 1; k <= n; k++) {
				for(i = 1; i <= n; i++) {
					for(j = 1; j <= n; j++) {
						double temp = table[step-1][i][k] * table[1][k][j];

						if(temp > table[step][i][j]) {
							table[step][i][j] = temp;
							path[step][i][j] = k; //since path[1][i][j] = k;
						}
					}
				}
			}

			for(i = 1; i <= n && !tf; i++) {
				if(table[step][i][i] > 1.01) {
					tf = true;
					printpath(step, i, path[step][i][i]);
					printf("%d\n", i);
				}
			}
		}

		if(!tf) printf("no arbitrage sequence exists\n");
	}
}
