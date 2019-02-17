#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//dijkstra
#define MX 20100
ll dist[MX];
vector <pair<ll, ll> > edges[MX];
void dijkstra(ll src)
{
    fill(dist, dist+MX, INT_MAX);

    priority_queue <pair<ll, ll>, vector<pair<ll, ll> >, greater <pair<ll, ll> > > pq;
    dist[src] = 0;
    pq.push(make_pair(dist[src], src));

    while(!pq.empty())
    {
        ll x = pq.top().second, y = pq.top().first;
        pq.pop();

        if(y != dist[x] && dist[x] != INT_MAX) continue;

        for(int i = 0; i < edges[x].size(); i++)
        {
            ll edg = edges[x][i].first, cst = edges[x][i].second;
            if(dist[edg] > dist[x]+cst) {
                dist[edg] = dist[x]+cst;
                pq.push(make_pair(dist[edg], edg));
            }
        }
    }
}

int main()
{
    int test;
    cin>>test;
    for(int t = 1; t <= test; t++) {
        int nodes, edge, S, T;
        cin>>nodes>>edge>>S>>T;

        for(int i = 0; i < edge; i++) {
            ll x, y, w;
            cin>>x>>y>>w;
            edges[x].push_back(make_pair(y, w));
            edges[y].push_back(make_pair(x, w));
        }

        dijkstra(S);

        if(dist[T] == INT_MAX) printf("Case #%d: unreachable\n", t);
        else printf("Case #%d: %d\n", t, dist[T]);

        //clearing
        for(int i = 0; i < MX; i++)
            edges[i].clear();
    }
}
