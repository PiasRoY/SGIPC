#include <bits/stdc++.h>
using namespace std;

#define MX 25
int d1[] = {1, -1, 0, 0};
int d2[] = {0, 0, 1, -1};
int cnt, n, m;
bool vis[MX][MX];
char grid[MX][MX], land;
void dfs(int x, int y)
{
	cnt++;
	vis[x][y] = 1;
	for(int i = 0; i < 4; i++) {
		int tx = x + d1[i], ty = (y + d2[i] + m) % m;

		if(tx < 0 || tx >= n || vis[tx][ty] || grid[tx][ty] != land) continue;
		dfs(tx, ty);
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	while(scanf("%d %d", &n, &m) != EOF) {
		getchar();

		char ch;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				scanf("%c", &ch);
				grid[i][j] = ch;
			}
			getchar();
		}

		int x, y;
		scanf("%d %d", &x, &y);

		memset(vis, false, sizeof vis);
		land = grid[x][y];
		dfs(x, y);

		int mx = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j  < m; j++) {
				if(!vis[i][j] && grid[i][j] == land) {
					cnt = 0;
					dfs(i, j);
					mx = max(mx, cnt);
				}
			}
		}

		printf("%d\n", mx);
	}
}
