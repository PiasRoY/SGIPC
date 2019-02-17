#include <bits/stdc++.h>
using namespace std;

#define MX 1005
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>
pii point[MX];
int parent[MX], n, r, state;
double mst, road, rail;
vector <pair<double, pii> > edgelist;

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
	state = mst = road = rail = 0;
	for(int i = 0; i < edgelist.size(); i++) {
		auto u = edgelist[i];
		int pu = find(u.ss.ff);
		int pv = find(u.ss.ss);

		if(pu != pv) {
			parent[pu] = pv;
			mst += u.ff;
			if(u.ff > r) rail += u.ff, state++;
			else road += u.ff;
			if(++cnt == n-1) break;
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

	for(int t = 1; t <= test; t++) {
		scanf("%d %d", &n, &r);

		int x, y;
		for(int i = 0; i < n; i++) {
			scanf("%d %d", &x, &y);
			point[i] = mp(x, y);
		}

		edgelist.clear();
		for(int i = 0; i < n; i++) {
			for(int j = i+1; j < n; j++) {
				edgelist.pb(mp(distant(point[i], point[j]), mp(i, j)));
			}
		}

		kruskal();

		printf("Case #%d: %d %.0f %.0f\n", t, state+1, road, rail);
	}
}
