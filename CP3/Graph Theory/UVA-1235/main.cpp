#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MX 500
#define pll pair<ll, ll>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

ll parent[MX], mst;
vector <string> vertices;
vector <pair<ll, pll > > edgeslist;

ll find(ll u)
{
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void kruskal_algo()
{
    for(ll i = 0; i < MX; i++)
        parent[i] = i;

    sort(edgeslist.begin(), edgeslist.end());

    mst = 0;
    //can't have more than one edge from "0000" node because it's not one of the unlocked keys to be jumped.
    bool tf = true;
    for(ll i = 0; i < edgeslist.size(); i++) {
		auto u = edgeslist[i];

		if(u.ss.ff == 0 || u.ss.ss == 0) {
            if(tf) tf = false;
            else continue;
		}

        ll pu = find(u.ss.ff);
        ll pv = find(u.ss.ss);

        if(pu != pv) {
            parent[pv] = pu;
            mst += u.ff;
        }
    }
}


ll min_edge(string x, string y)
{
    ll a, b, sum = 0;
    for(int i = 0; i < 4; i++) {
        a = x[i]-'0', b = y[i]-'0';
        a = abs(a-b);
        if(a > 5) a = 10-a;
        sum += a;
    }
    return sum;
}

int main()
{
    int test;
    scanf("%d", &test);

    for(int t = 1; t <= test; t++) {
        ll n, value, k = 0;
        scanf("%lld", &n);

		string x;
        vertices.push_back("0000");
        for(ll i = 0; i < n; i++) {
            cin>>x;

            ll l = vertices.size();
            for(ll i = 0; i < l; i++)
            {
            	edgeslist.pb(mp(min_edge(vertices[i], x), mp(i, l)));
            }
            vertices.push_back(x);
        }

        kruskal_algo();

        printf("%lld\n", mst);

        //clearing
        vertices.clear(), edgeslist.clear();
    }
}
