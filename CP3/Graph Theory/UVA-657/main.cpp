#include <bits/stdc++.h>
using namespace std;

int cnt, h, w;
int d1[] = {1, -1, 0, 0};
int d2[] = {0, 0, 1, -1};
char grid[100][100];

void dfs2(int x, int y)
{
	for(int i = 0; i < 4; i++) {
		int tx = x + d1[i], ty = y + d2[i];

		if(tx < 0 || ty < 0 || tx >= h || ty >= w || grid[tx][ty] != 'X') continue;

		grid[tx][ty] = '*';
		dfs2(tx, ty);
	}
}

void dfs(int x, int y)
{
	for(int i = 0; i < 4; i++) {
		int tx = x + d1[i], ty = y + d2[i];

		if(tx < 0 || ty < 0 || tx >= h || ty >= w || grid[tx][ty] == '.') continue;

		if(grid[tx][ty] == 'X') dfs2(tx, ty), cnt++;

		grid[tx][ty] = '.';
		dfs(tx, ty);
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t = 1;
	while(scanf("%d %d", &w, &h) && w+h)
	{
		for(int i = 0; i < h; i++) {
			getchar();
			for(int j = 0; j < w; j++) {
				scanf("%c", &grid[i][j]);
			}
		}

		vector <int> v;
		printf("Throw %d\n", t++);
		for(int i = 0; i < h; i++) {
			for(int j = 0; j < w; j++) {
				if(grid[i][j] != '.') {
					cnt = 0;
					dfs(i, j);
					v.push_back(cnt);
				}
			}
		}

		sort(v.begin(), v.end());
		for(int i = 0; i < v.size()-1; i++)
			printf("%d ", v[i]);
		printf("%d\n\n", *v.rbegin());
	}
}
