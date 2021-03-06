#include <bits/stdc++.h>
using namespace std;

vector <int> adj[50];
bool vis[50];
void dfs(int u)
{
	if(vis[u]) return;
	vis[u] = true;

	for(int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		dfs(v);
	}
}

int main()
{
	int test;
	scanf("%d", &test);

	string s;
	cin>>s;
	for(int t = 1; t <= test; t++) {
		memset(vis, 0, sizeof vis);
		for(int i = 0; i < 50; i++)
			adj[i].clear();

		int x = s[0] - 'A';
		while(cin>>s && s.size() != 1) {
			adj[s[0]-'A'].push_back(s[1]-'A');
			adj[s[1]-'A'].push_back(s[0]-'A');
		}

		int cnt = 0;
		for(int i = 0; i <= x; i++) {
			if(!vis[i]) {
				cnt++;
				dfs(i);
			}
		}

		printf("%d\n", cnt);
		if(t != test) printf("\n");
	}
}
