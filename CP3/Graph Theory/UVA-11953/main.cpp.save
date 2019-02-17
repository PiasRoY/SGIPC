#include <bits/stdc++.h>
using namespace std;

#define MX 105
int d1[] = {1, -1, 0, 0};
int d2[] = {0, 0, 1, -1};
int n;
bool vis[MX][MX];
char grid[MX][MX];
void dfs(int x, int y)
{
	vis[x][y] = 1;
	for(int i = 0; i < 4; i++) {
		int tx = x + d1[i], ty = y + d2[i];

		if(tx < 0 || tx >= n || ty < 0 || ty >= n || vis[tx][ty] || grid[tx][ty] == '.') continue;
		dfs(tx, ty);
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int test;
	scanf("%d", &test);

	for(int  t = 1; t <= test; t++) {
		scanf("%d", &n);
		getchar();

		char ch;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				scanf("%c", &ch);
				grid[i][j] = ch;
			}
			getchar();
		}

		memset(vis, false, sizeof vis);
		int cnt = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j  < n; j++) {
				if(!vis[i][j] && grid[i][j] == 'x') {
					cnt++;
					dfs(i, j);
				}
			}
		}

		printf("Case %d: %d\n", t, cnt);
	}
}
