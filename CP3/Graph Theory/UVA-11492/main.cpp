#include <bits/stdc++.h>
using namespace std;

#define MX 20000
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define inf 100000000
#define pii pair<int, int>

int dist[MX];
bool vis[MX];
map <string, int> mp1, word;
vector <string> lang[MX];
vector <pair<int, int> > adj[MX];

void djk(int src)
{
	fill(dist, dist+MX, inf);
	fill(vis, vis+MX, false);

	priority_queue <pii, vector<pii>, greater<pii> > pq;
	pq.push(mp(0, src));
	dist[src] = 0;

	while(!pq.empty()) {
		auto u = pq.top();
		pq.pop();

		if(vis[u.ss]) continue;

		vis[u.ss] = true;
		for(int i = 0; i < adj[u.ss].size(); i++) {
			auto v = adj[u.ss][i];

			if(dist[v.ff] > dist[u.ss] + v.ss) {
				dist[v.ff] = dist[u.ss] + v.ss;
				pq.push(mp(dist[v.ff], v.ff));
			}
		}
	}
}

void reset()
{
	mp1.clear(), word.clear();
	for(int i = 0; i < MX; i++)
		adj[i].clear(), lang[i].clear();
}

int main()
{
	int n, k, z, l1, l2;
	string s, f, x, y, w;
	while(scanf("%d", &n) && n) {
		reset();

		cin>>s>>f;

		k = z = 0;
		mp1[s] = k++;
		mp1[f] = k++;

		for(int i = 0; i < n; i++) {
			cin>>x>>y>>w;

			if(mp1.find(x) == mp1.end()) mp1[x] = l1 = k++;
			else l1 = mp1[x];

			if(mp1.find(y) == mp1.end()) mp1[y] = l2 = k++;
			else l2 = mp1[y];

			word[w] = ++z;
//			cout<<l1<<" "<<l2<<" "<<z<<endl;

			for(int i = 0; i < lang[l1].size(); i++) {
				x = lang[l1][i];
				if(x[0] != w[0]) {
					adj[word[x]].pb(mp(z, w.size()));
					adj[z].pb(mp(word[x], x.size()));
				}
			}

			for(int i = 0; i < lang[l2].size(); i++) {
				x = lang[l2][i];
				if(x[0] != w[0]) {
					adj[word[x]].pb(mp(z, w.size()));
					adj[z].pb(mp(word[x], x.size()));
				}
			}

			lang[l1].pb(w);
			lang[l2].pb(w);
		}

		l1 = mp1[s], l2 = mp1[f];
		for(int i = 0; i < lang[l1].size(); i++) //connecting all words of first language to '0' node.
		{
			x = lang[l1][i];
			adj[0].pb(mp(word[x], x.size()));
		}
		for(int i = 0; i < lang[l2].size(); i++) //connecting all words of finish language to 'z+1' node.
		{
			x = lang[l2][i];
			adj[word[x]].pb(mp(z+1, 0));
		}

//		for(int i = 1; i <= n; i++) {
//			cout<<i<<" : ";
//			for(auto e : adj[i])
//				cout<<"("<<e.ff<<","<<e.ss<<") ";
//			cout<<endl;
//		}

		djk(0);

		if(!vis[z+1]) printf("impossivel\n");
		else printf("%d\n", dist[z+1]);
	}
}


