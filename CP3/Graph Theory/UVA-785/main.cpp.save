#include <bits/stdc++.h>
using namespace std;

int d1[] = {1, -1, 0, 0};
int d2[] = {0, 0, 1, -1};
char grid[40][100];
bool vis[100][100];
int h;
char bd, color;

void dfs(int x, int y)
{
	vis[x][y] = true;

	grid[x][y] = color;
	for(int i = 0; i < 4; i++) {
		int tx = x + d1[i], ty = y + d2[i], l = strlen(grid[tx]);
		if(tx < 0 || ty < 0 || tx > h || ty >= l || vis[tx][ty] || grid[tx][ty] == bd) continue;

		dfs(tx, ty);
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int i = -1;

	while(gets(grid[++i]))
	{
		if(grid[i][0] == '_') {
			memset(vis, false, sizeof vis);
			h = i-1;

			bool tf = true;
			for(int k = 0; k < i; k++) {
				for(int j = 0; j < strlen(grid[k]); j++) {
					if(tf && grid[k][j] != ' ') {
						bd = grid[k][j];
						tf = false;
						break;
					}
				}
				if(!tf) break;
			}

			for(int k = 0; k < i; k++) {
				for(int j = 0; j < strlen(grid[k]); j++) {
					if(!vis[k][j] && grid[k][j] != ' ' && grid[k][j] != bd) {
						color = grid[k][j];
						dfs(k, j);
					}
				}
			}

			for(int k = 0; k <= i; k++) {
				printf("%s\n", grid[k]);
			}

			i = -1;
		}
	}
}
