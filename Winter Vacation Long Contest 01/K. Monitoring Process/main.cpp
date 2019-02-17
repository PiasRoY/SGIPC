#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define MX 65
#define mod 100000007
#define inf 0x3f3f3f3f
#define pi acos(-1)
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<ll, ll>

int main()
{
	int test;
	scanf("%d", &test);

	int n, l, r;
	vector <pii> v;
	priority_queue <int, vector<int>, greater<int> > pq;

	for(int t = 1; t <= test; t++) {
		scanf("%d", &n);

		for(int i = 0; i < n; i++) {
			scanf("%d %d", &l, &r);
			v.pb(mk(l, r));
		}

		sort(v.begin(), v.end());

		for(auto e : v) {
			pq.push(e.ss);

			if(e.ff > pq.top())
				pq.pop();
		}

		printf("Case %d: %d\n", t, pq.size());

		//clearing
		v.clear();
		while(!pq.empty()) pq.pop();
	}
}
