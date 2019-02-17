#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
typedef long long ll;
typedef pair<ll, ll> pll;

//disjoint set
#define MX 500000
ll par[MX], u, v, cnt;
ll find(ll x)
{
    if(x == par[x]) return x;
    return par[x] = find(par[x]);
}
ll initial()
{
    cnt = 0;
    for(ll i = 0; i < MX; i++)
        par[i] = i;
}

int main()
{
    initial();
    while(cin>>u) {
        if(u == -1) {
            cout<<cnt<<endl;
            initial();
            continue;
        }
        cin>>v;

        ll pu = find(u), pv = find(v);

        if(pu == pv) cnt++;
        else par[pv] = pu;
    }
}
