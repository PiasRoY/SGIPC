#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define MX 105
#define mod 100000007
#define inf 0x3f3f3f3f
#define pi acos(-1)
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define pii pair<int, int>

int dp[MX][MX];

int f(int l, int r)
{
	if(l > r) return 0;

	int &ret = dp[l][r];
	if(ret != -1) return ret;

	int ret1 = -inf, ret2 = -inf, sum;

	sum = 0;
	for(int left = l; left <= r; left++) {
		sum += dp[left][left];
		ret1 = max(ret1, sum-f(left+1, r));
	}

	sum = 0;
	for(int right = r; right >= l; right--) {
		sum += dp[right][right];
		ret2 = max(ret2, sum-f(l, right-1));
	}

	return ret = max(ret1, ret2);
}

int main()
{
	int test;
	cin>>test;

	int n, ans, sum;

	for(int t = 1; t <= test; t++) {
		cin>>n;

		memset(dp, -1, sizeof dp);

		sum = 0;
		for(int i = 0; i < n; i++) cin>>dp[i][i], sum += dp[i][i];

		ans = f(0, n-1);

		printf("Case %d: %d\n", t, ans);
	}
}
