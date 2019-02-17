#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;

int d1[] = {1, 1, -1, -1};
int d2[] = {1, -1, 1, -1};

#define MX 200
int e, o, r, c, n, m;
bool vis[MX][MX], grid[MX][MX];

void dfs(int x, int y)
{
	if(grid[x][y]) return;

	vis[x][y] = true;
	set <pair<int, int> > s;

	int tx, ty;
	for(int i = 0; i < 4; i++) {
		tx = x+(d1[i]*n), ty = y+(d2[i]*m);
		if(tx >= 0 && tx < r && ty >= 0 && ty < c && !grid[tx][ty]) {
			if(!vis[tx][ty]) dfs(tx, ty);
			s.insert({tx, ty});
		}
	}
	for(int i = 0; i < 4; i++) {
		tx = x+(d1[i]*m), ty = y+(d2[i]*n);
		if(tx >= 0 && tx < r && ty >= 0 && ty < c && !grid[tx][ty]) {
			if(!vis[tx][ty]) dfs(tx, ty);
			s.insert({tx, ty});
		}
	}
//	cout<<x<<" "<<y<<" "<<s.size()<<endl;
	if(!s.empty() && s.size() % 2 == 0) e++;
	else if(s.size() % 2) o++;

	s.clear();
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int test;
	scanf("%d", &test);

	int w, x, y, tx, ty;
	for(int t = 1; t <= test; t++) {
		scanf("%d %d %d %d", &r, &c, &n, &m);

		memset(grid, false, sizeof grid);
		memset(vis, false, sizeof vis);
		scanf("%d", &w);
		while(w--) {
			scanf("%d %d", &x, &y);
			grid[x][y] = true;
		}

		e = 0, o = 0;
		dfs(0, 0);

		if(e == 0 && o == 0) e = 1;
		printf("Case %d: %d %d\n", t, e, o);
	}
}
