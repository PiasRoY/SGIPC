#include <bits/stdc++.h>
using namespace std;

#define MX 105
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

vector <int> adj[MX], ans;
map <string, int> mp1;
map <int, string> mp2;
int in_degree[MX], level[MX], k;

void bfs()
{
	priority_queue <int, vector <int>, greater<int> > q;

	for(int i = 0; i < k; i++)
		if(in_degree[i] == 0)
			q.push(i), level[i] = 0;

	int cnt = 0;
	while(!q.empty()) {
		int x = q.top();
		cnt++;
		q.pop();
		ans.pb(x);

		for(int i = 0; i < adj[x].size(); i++) {
			int u = adj[x][i];

			if(--in_degree[u] == 0) {
				level[u] = level[x] + 1;
				q.push(u);
			}
		}
	}
}

void reset()
{
	ans.clear();
	for(int i = 0; i < MX; i++)
		adj[i].clear();
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n, test = 1;
	string s, t;
	while(scanf("%d", &n) != EOF) {
		reset();

		k = 0;
		for(int i = 0; i < n; i++) {
			cin>>s;
			mp1[s] = k;
			mp2[k++] = s;
		}

		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			cin>>s>>t;

			int x = mp1[s], y = mp1[t];
			adj[x].pb(y);
			in_degree[y]++;
		}

		bfs();

		printf("Case #%d: Dilbert should drink beverages in this order: ", test++);
		cout<<mp2[ans[0]];
		for(int i = 1; i < k; i++)
			cout<<" "<<mp2[ans[i]];
		printf(".\n\n");
	}
}
