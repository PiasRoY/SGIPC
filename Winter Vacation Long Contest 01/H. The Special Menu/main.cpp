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

string s;
ll ans, dp[MX][MX];

ll f(int l, int r)
{
	if(l == r) return 1;
	else if(l > r) return 0;

	ll &ret = dp[l][r];
	if(ret != -1) return ret;

	ret = 0;
	if(s[l] == s[r]) {
		ret = f(l+1, r-1) + 1;
	}

	ret +=  f(l, r-1) + f(l+1, r) - f(l+1, r-1);

	return ret;
}

int main()
{
	int test;
	scanf("%d", &test);

	for(int t = 1; t <= test; t++) {
		cin>>s;

		memset(dp, -1, sizeof dp);
		ans = f(0, s.size()-1);

		printf("Case %d: %lld\n", t, ans);
	}
}
