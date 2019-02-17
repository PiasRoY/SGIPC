#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAX 200
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>

ll mst, s_mst;
int parent[MAX], n;
vector <int> mst_edge;
vector <pair<int, pii> > edgelist;

int find(int u)
{
	if(parent[u] == u) return u;
	return parent[u] = find(parent[u]);
}

bool kruskal()
{
	for(int i = 0; i <= n; i++) parent[i] = i;
	sort(edgelist.begin(), edgelist.end());

	int cnt = 0; mst = 0;
	for(int i = 0; i < edgelist.size(); i++) {
		int pu = find(edgelist[i].ss.ff);
		int pv = find(edgelist[i].ss.ss);

		if(pu != pv){
			parent[pu] = pv;
			mst += edgelist[i].ff;
			mst_edge.pb(i);
			cnt++;
			if(cnt == n-1) break;
		}
	}

	if(cnt != n-1) return false;
	return true;
}

bool sec_mst()
{
	ll mn, cnt;
	s_mst = LLONG_MAX;
	bool tf = false;

	for(int j = 0; j < mst_edge.size(); j++) {
		mn = 0, cnt = 0;
		for(int i = 0; i <= n; i++) parent[i] = i;
		for(int i = 0; i < edgelist.size(); i++) {
			if(i == mst_edge[j]) continue;

			auto u = edgelist[i];
			int pu = find(u.ss.ff);
			int pv = find(u.ss.ss);

			if(pu != pv){
				parent[pu] = pv;
				mn += u.ff;
				cnt++;
				if(cnt == n-1) {
					tf = true;
					break;
				}
			}
		}
		if(cnt == n-1) s_mst = min(s_mst, mn);
	}

	return tf;
}

int main()
{
	int test;
	scanf("%d", &test);

	int m, x, y, w;
	for(ll t = 1; t <= test; t++){
		scanf("%d %d", &n, &m);

		while(m--){
			scanf("%d %d %d", &x, &y, &w);
			edgelist.push_back(mp(w, mp(x, y)));
		}

		kruskal();
		sec_mst();
		printf("%lld %lld\n", mst, s_mst);

		//clearing
		edgelist.clear();
		mst_edge.clear();
	}
}
