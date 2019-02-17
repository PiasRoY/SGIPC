#include <bits/stdc++.h>
using namespace std;

#define MX 1000
bool vis[MX][MX];
char grid[MX][MX];
int d1[] = {1,1,0,-1,-1,-1,0,1};
int d2[] = {0,1,1,1,0,-1,-1,-1};

int dfs(int x, int y)
{
	vis[x][y] = 1;
//	cout<<x<<" "<<y<<endl;
	int cnt = 1;
	for(int i = 0; i < 8; i++)
	{
		int tx = x + d1[i], ty = y + d2[i];
		if(tx < 0 || ty < 0 || grid[tx][ty] != 'W' || vis[tx][ty]) continue;

		cnt += dfs(tx, ty);
	}

	return cnt;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int test;
	scanf("%d", &test);
	getchar();
	getchar();
	int i, x, y, str;
	while(test--) {
		i = -1, str = -1;
		memset(grid, -1, sizeof grid);

		while(gets(grid[++i]) && strlen(grid[i]) != 0) {
			if(str == -1 && (grid[i][0] >= '0' && grid[i][0] <= '9'))
				str = i;
		}

		int x, y;
		for(int j = str; j < i; j++) {
			sscanf(grid[j], "%d %d", &x, &y);
			x--, y--;

			memset(vis, 0, sizeof vis);
			printf("%d\n", dfs(x, y));
		}

		if(test != 0) printf("\n");
	}
}
