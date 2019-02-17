#include <bits/stdc++.h>
using namespace std;

#define MX 105
#define inf 1e9
int mat[MX][MX];

void floydwarshall()
{
	for(int k = 1; k <= 100; k++) {
		for(int i = 1; i <= 100; i++) {
			for(int j = 1; j <= 100; j++) {
				if(mat[i][j] > mat[i][k] + mat[k][j])
					mat[i][j] = mat[i][k] + mat[k][j];
			}
		}
	}
}

void reset()
{
	for(int i = 0; i < MX; i++)
		for(int j = 0; j < MX; j++)
			if(i == j) mat[i][j] = 0;
			else mat[i][j] = inf;
}

int main()
{
	int x, y, test = 0;
	while(scanf("%d %d", &x, &y) && x+y) {
		reset();

		mat[x][y] = 1;
		while(scanf("%d %d", &x, &y) && x+y)
			mat[x][y] = 1;


		floydwarshall();

		double sum, cnt;
		sum = cnt = 0;
		for(int i = 1; i <= 100; i++) {
			for(int j = 1; j <= 100; j++) {
				if(mat[i][j] != inf && mat[i][j] != 0) {
					sum += mat[i][j];
					cnt++;
				}
			}
		}

		printf("Case %d: average length between pages = %.3f clicks\n", ++test, (sum/cnt));
	}
}
