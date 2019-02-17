#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
typedef long long ll;
typedef pair<ll, ll> pll;

//kruskal_algo
#define MX 5000
ll parent[MX], mst;
vector <pair<ll, pair<ll, ll> > > edgeslist;

ll find(ll x)
{
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void kruskal_algo()
{
    for(ll i = 0; i < MX; i++)
        parent[i] = i;

    sort(edgeslist.begin(), edgeslist.end());

    mst = 0;
    for(ll i = 0; i < edgeslist.size(); i++) {
        ll pu = find(edgeslist[i].second.first);
        ll pv = find(edgeslist[i].second.second);

        if(pu != pv) {
            parent[pv] = pu;
            mst += edgeslist[i].first;
        }
    }
}

int main()
{
    int test;
    scanf("%d", &test);

    for(int t = 1; t <= test; t++) {
        ll n, m, w, k = 0;
        scanf("%lld %lld", &n, &m);

        string u, v;
        map <string, ll> mmp;

        for(ll i = 0; i < m; i++) {
            cin>>u>>v>>w;

            if(mmp.find(u) == mmp.end()) mmp[u] = k++;
            if(mmp.find(v) == mmp.end()) mmp[v] = k++;

            edgeslist.push_back(mp(w, mp(mmp[u], mmp[v])));
        }

        kruskal_algo();

        printf("%lld\n", mst);
        if(t != test) printf("\n");
        //clearing
        edgeslist.clear();
    }
}
