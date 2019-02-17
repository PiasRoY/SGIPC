#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MX 10005
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ppii pair<int, pair<int, int> >
ll mst;
int n, parent[MX];
vector <ppii> edgelist;

int find(int u)
{
	if(parent[u] == u) return u;
	return parent[u] = find(parent[u]);
}

bool cmp(ppii a, ppii b)
{
	if(a.ff > b.ff) return true;
	if(a.ff == b.ff) {
		if(a.ss.ff < b.ss.ff) return true;
		if(a.ss.ff == b.ss.ff) {
			if(a.ss.ss < b.ss.ss) return true;
		}
	}
	return false;
}

void kruskal()
{
	for(int i = 0; i <= n; i++) parent[i] = i;
	sort(edgelist.begin(), edgelist.end(), cmp);

	mst = 0;
	int cnt = 0;
	for(int i = 0; i < edgelist.size(); i++) {
		auto u = edgelist[i];
		int pu = find(u.ss.ff);
		int pv = find(u.ss.ss);

		if(pu != pv) {
			parent[pu] = pv;
			mst += u.ff;
			if(++cnt == n-1) break;
		}
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int test;
	scanf("%d", &test);

	ll EdgeCostSum;
	int m, x, y, w;
	for(int t = 1; t <= test; t++) {
		scanf("%d %d", &n, &m);

		EdgeCostSum = 0; edgelist.clear();
		for(int i = 0; i < m; i++) {
			scanf("%d %d %d", &x, &y, &w);
			EdgeCostSum += w;
			edgelist.pb(mp(w, mp(x, y)));
		}

		kruskal();
		printf("%d\n", EdgeCostSum-mst);
	}
}
