#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MX 505
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>
pii point[MX];
int parent[MX], mst, s, p;
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

	int cnt = s-1;
	for(int i = 0; i < edgelist.size(); i++) {
		auto u = edgelist[i];
		int pu = find(u.ss.ff);
		int pv = find(u.ss.ss);

		if(pu != pv) {
			parent[pu] = pv;
			if(++cnt == p-1) {
				printf("%.2f\n", u.ff);
				break;
			}
		}
	}
}

double distant(pii a, pii b)
{
	double x = a.ff-b.ff, y = a.ss-b.ss;
	return sqrt((x*x)+(y*y));
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int test;
	scanf("%d", &test);

	for(int t = 1; t <= test; t++) {
		scanf("%d %d", &s, &p);
		for(int i = 0; i < p; i++) {
			scanf("%d %d", &point[i].ff, &point[i].ss);
		}

		for(int i = 0; i < p; i++) {
			for(int j = i+1; j < p; j++) {
				edgelist.pb(mp(distant(point[i], point[j]), mp(i, j)));
			}
		}

		kruskal();

		//clearing
		edgelist.clear();
	}
}
