#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

#define MX 500
bool grid[MX][MX];

void convert(string s, int h)
{
	int x, y;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] >= 'a') x = 10 + (s[i]-'a');
		else x = s[i]-'0';

		for(int j = 3; j >= 0; j--) {
			y = (x & (1<<j)) ? 1 : 0;
			grid[h][(i*4)+(3-j)] = y;
		}
	}
}

int cnt, h, w;
int vis[MX][MX];
int d1[] = {1, -1, 0, 0};
int d2[] = {0, 0, 1, -1};
void dfs2(int x, int y)
{
	vis[x][y] = true;
	for(int i = 0; i < 4; i++) {
		int tx = x + d1[i], ty = y + d2[i];

		if(tx < 0 || ty < 0 || tx >= h || ty >= w || vis[tx][ty] || grid[tx][ty]) continue;

		dfs2(tx, ty);
	}
}
void dfs(int x, int y)
{
	vis[x][y] = true;
	for(int i = 0; i < 4; i++) {
		int tx = x + d1[i], ty = y + d2[i];

		if(tx < 0 || ty < 0 || tx >= h || ty >= w || vis[tx][ty]) continue;

		if(grid[tx][ty]) dfs(tx, ty);
		else dfs2(tx, ty), cnt++;
	}
}

int main()
{
	int t = 1;
	string s;
	while(scanf("%d %d", &h, &w) && h+w)
	{
		vector <char> v;
		memset(vis, 0, sizeof vis);
		memset(grid, 0, sizeof grid);

		for(int i = 1; i <= h; i++) {
			cin>>s;
			s = "0" + s + "0";
			convert(s, i);
		}

		h = h + 5, w = (w+2)*4 + 5;

		dfs2(0, 0);
		for(int i = 0; i < h; i++) {
			for(int j = 0; j < w; j++) {
				if(!vis[i][j] && grid[i][j]) {
					cnt = 0;
					dfs(i, j);
					if(cnt == 0) v.push_back('W');
					else if(cnt == 1) v.push_back('A');
					else if(cnt == 2) v.push_back('K');
					else if(cnt == 3) v.push_back('J');
					else if(cnt == 4) v.push_back('S');
					else if(cnt == 5) v.push_back('D');
				}
			}
		}

		sort(v.begin(), v.end());

		printf("Case %d: ", t++);
		for(int i = 0; i < v.size(); i++)
			printf("%c", v[i]);
		printf("\n");
	}

}
