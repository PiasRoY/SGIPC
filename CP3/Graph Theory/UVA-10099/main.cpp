#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
typedef long long ll;
typedef pair<ll, ll> pll;

//Kruskal
#define MX 105
ll par[MX];
vector <pll> edges[MX];
vector <pair<ll, pair<ll, ll> > > edgeslist;

ll find(ll x)
{
    if(x == par[x]) return x;
    return par[x] = find(par[x]);
}

void kruskal()
{
    for(ll i = 0; i < MX; i++)
        par[i] = i, edges[i].clear();

    sort(edgeslist.begin(), edgeslist.end());

    for(ll i = edgeslist.size()-1; i >= 0; i--) {
        ll u = edgeslist[i].second.first, v = edgeslist[i].second.second;
        ll w = edgeslist[i].first;
        ll pu = find(u), pv = find(v);

        if(pu != pv) {
            par[pv] = pu;
            edges[u].push_back(mp(v, w));
            edges[v].push_back(mp(u, w));
        }
    }
}

//dfs
ll min_edg, s, d, t;
bool vis[MX];
void dfs(ll node, ll mini)
{
    if(node == d) {
        min_edg = mini;
        return;
    }
    if(vis[node]) return;
    vis[node] = true;

    for(ll i = 0; i < edges[node].size(); i++) {
        ll edg = edges[node][i].first, cst = edges[node][i].second;
        if(!vis[edg]) {
            dfs(edg, cst<mini?cst:mini);
        }
    }
}

int main()
{
    ll n, m, test = 1;
    while(scanf("%lld %lld", &n, &m) && n+m) {
        ll u, v, w;
        for(ll i = 0; i < m; i++) {
            scanf("%lld %lld %lld", &u, &v, &w);
            edgeslist.push_back(mp(w, mp(u, v)));
        }

        scanf("%lld %lld %lld", &s, &d, &t);

        kruskal();
        fill(vis, vis+MX, 0);
        dfs(s, 1e+10);
        // cout<<min_edg<<endl;
        cout<<"Scenario #"<<test++<<endl<<"Minimum Number of Trips = "<<ceil(1.0*t/(min_edg-1))<<endl<<endl;

        //clearing
        edgeslist.clear();
    }
}
