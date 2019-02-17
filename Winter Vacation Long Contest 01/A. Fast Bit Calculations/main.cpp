#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define MX 32
#define mod 100000007
#define inf 0x3f3f3f3f
#define pi acos(-1)
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define pii pair<int, int>

vector <ll> bin;
ll dp[MX][MX][2][2];

ll f(ll pos, ll sum, ll prev, ll tf)
{
	if(pos == bin.size()) return sum;

	ll &ret = dp[pos][sum][prev][tf];
	if(ret != -1) return ret;

	ll lmt;

	if(tf) lmt = 1;
	else lmt = bin[pos];

	ret = 0;

	for(ll dgt = 0; dgt <= lmt; dgt++) {
		ll nf = tf;
		if(!tf && dgt < lmt) nf = 1;

		if(prev & dgt)
			ret += f(pos+1, sum+1, dgt, nf);
		else
			ret += f(pos+1, sum, dgt, nf);
	}

	return ret;
}

ll solve(ll n)
{
	bin.clear();

	while(n) {
		bin.pb(n%2);
		n /= 2;
	}
	reverse(bin.begin(), bin.end());

	memset(dp, -1, sizeof dp);
	ll res = f(0, 0, 0, 0);

	return res;
}

int main()
{
	int test;
	scanf("%d", &test);

	ll n, ans;

	for(int t = 1; t <= test; t++) {
		scanf("%lld", &n);

		ans = solve(n);

		printf("Case %d: %lld\n", t, ans);
	}
}
