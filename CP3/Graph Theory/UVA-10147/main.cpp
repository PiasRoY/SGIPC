#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MX 10000
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
int n, m, cnt, parent[MX];
pair <int, int> point[MX];
vector <pair<double, pii> > edgelist;

int find(int u)
{
	if(parent[u] == u) return u;
	return parent[u] = find(parent[u]);
}

void kruskal()
{
	sort(edgelist.begin(), edgelist.end());

	for(int i = 0; i < edgelist.size(); i++) {
		auto u = edgelist[i];
		int pu = find(u.ss.ff);
		int pv = find(u.ss.ss);

		if(pu != pv) {
			printf("%d %d\n", u.ss.ff, u.ss.ss);
			parent[pu] = pv;
		}
	}
}

double distant(pii a, pii b)
{
	double x = abs(a.ff-b.ff), y = abs(a.ss-b.ss);
	return sqrt((x*x)+(y*y));
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int test;
	scanf("%d", &test);

	int x, y, w;
	for(int t = 1; t <= test; t++) {
		scanf("%d", &n);

		for(int i = 1; i <= n; i++) {
			scanf("%d %d", &x, &y);
			point[i] = mp(x, y);
		}

		cnt = 0;
		scanf("%d", &m);
		for(int i = 0; i < MX; i++) parent[i] = i;
		for(int i = 0; i < m; i++) {
			scanf("%d %d", &x, &y);

			int pu = find(x);
			int pv = find(y);
			if(pu != pv) {
				parent[pu] = pv;
				cnt++;
			}
		}


		edgelist.clear();
		for(int i = 1; i <= n; i++) {
			for(int j = i+1; j <= n; j++) {
				if(find(i) != find(j))
					edgelist.pb(mp(distant(point[i], point[j]), mp(i, j)));
			}
		}

		kruskal();
		if(cnt == n-1) printf("No new highways need\n");
		if(t != test) printf("\n");
	}
}
