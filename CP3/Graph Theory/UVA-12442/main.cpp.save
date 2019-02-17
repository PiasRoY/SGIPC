#include <bits/stdc++.h>
using namespace std;

#define MX 50005
bool tf;
int adj[MX], vis[MX], pcnt, acnt;
void dfs(int x)
{
	if(vis[x] == -1) {
		tf = false;
		acnt = pcnt;
		return;
	}
	else if(vis[x] != 0) {
		tf = true;
		acnt += vis[x];
		return;
	}

	vis[x] = -1;
	pcnt++;
	dfs(adj[x]);
	if(tf) acnt++;
	vis[x] = acnt;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int test;
	scanf("%d", &test);

	for(int t = 1; t <= test; t++) {
		int n;
		scanf("%d", &n);

		int x, y;
		for(int i = 0; i < n; i++) {
			scanf("%d %d", &x, &y);
			adj[x] = y;
		}

		int ans, mx = 0;
		memset(vis, 0, sizeof vis);
		vis[0] = -1;
		for(int i = 1; i <= n; i++) {
			if(!vis[i]) {
				acnt = pcnt = 0;
				dfs(i);
				if(vis[i] > mx) mx = vis[i], ans = i;
			}
		}

		printf("Case %d: %d\n", t, ans);
	}
}
