#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int d1[] = {-1, 0, 1, 0};
int d2[] = {0, 1, 0, -1};
#define MX 105
char grid[MX][MX];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n, m, r;
	while(scanf("%d %d %d", &n, &m, &r) && n+m+r) {
		getchar();

		int sx, sy, tx, ty, d;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				scanf("%c", &grid[i][j]);
				if(grid[i][j] == 'N') d = 0, sx = i, sy = j;
				else if(grid[i][j] == 'L') d = 1, sx = i, sy = j;
				else if(grid[i][j] == 'S') d = 2, sx = i, sy = j;
				else if(grid[i][j] == 'O') d = 3, sx = i, sy = j;
			}
			getchar();
		}

		char ch;
		int st = 0;
		for(int i = 0; i < r; i++) {
			scanf("%c", &ch);

			if(d == -1) d = 3;
			else if(d == 4) d = 0;

			if(ch == 'D') d++;
			else if(ch == 'E') d--;
			else {
				tx = sx + d1[d], ty = sy + d2[d];

				if(grid[tx][ty] != '#' && tx >= 0 && tx < n && ty >= 0 && ty < m) {
					sx = tx, sy = ty;
					if(grid[sx][sy] == '*') st++, grid[sx][sy] = '.';
				}
			}
		}

		printf("%d\n", st);
	}


}
