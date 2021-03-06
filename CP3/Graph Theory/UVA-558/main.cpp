#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

class edge
{
public:
    ll u, v, w;
};

#define MX 100000
ll dist[MX];
ll nodes, edges;
vector <edge> edgelist;
bool bellman_ford(ll src)
{
    fill(dist, dist+nodes, 1e+18);
    dist[src] = 0;

    for(ll i = 1; i < nodes; i++) {
        for(ll e = 0; e < edges; e++) {
            if(dist[edgelist[e].v] > dist[edgelist[e].u]+edgelist[e].w)
                dist[edgelist[e].v] = dist[edgelist[e].u]+edgelist[e].w;
        }
    }

    for(ll e = 0; e < edges; e++) {
        if(dist[edgelist[e].v] > dist[edgelist[e].u]+edgelist[e].w)
            //negative cycle
            return true;
    }

    return false;
}

int main()
{
    int test;
    cin>>test;

    for(int t = 1; t <= test; t++)
    {
        cin>>nodes>>edges;
        for(ll e = 0; e < edges; e++)
        {
            edge E;
            cin>>E.u>>E.v>>E.w;
            edgelist.push_back(E);
        }

        if(bellman_ford(0)) cout<<"possible"<<endl;
        else cout<<"not possible"<<endl;

        //clearing
        edgelist.clear();
    }
}
