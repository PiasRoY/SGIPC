#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MX 200005
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>
ll mst;
int parent[MX], n, m;
vector <int> ans;
vector <pair<int, pii> > edgelist;
int find(int u)
{
	if(u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

void kruskal()
{
	for(int i = 0; i < MX; i++) parent[i] = i;
	sort(edgelist.begin(), edgelist.end());

	int cnt = 0;
	mst = 0;
	for(int i = 0; i < edgelist.size(); i++) {
		auto u = edgelist[i];
		int pu = find(u.ss.ff);
		int pv = find(u.ss.ss);

		if(pu != pv) {
			parent[pu] = pv;
			mst += u.ff;
		}
		else ans.pb(u.ff);
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int x, y, w;
	long long sum;
	while(scanf("%d %d", &n, &m) && n+m) {
		sum = 0;
		for(int i = 0; i < m; i++) {
			scanf("%d %d %d", &x, &y, &w);
			edgelist.pb(mp(w, mp(x, y)));
		}

		kruskal();

		if(ans.empty()) printf("forest\n");
		else {
			sort(ans.begin(), ans.end());
			printf("%d", ans[0]);
			for(int i = 1; i < ans.size(); i++)
				printf(" %d", ans[i]);
			printf("\n");
		}
		edgelist.clear(), ans.clear();
	}
}
