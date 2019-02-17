#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define MX 35
#define mod 100000007
#define inf 0x3f3f3f3f
#define pi acos(-1)
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<ll, ll>

int n, k, row[MX];
ll ans, dp[MX*MX][MX];

bool check(int col, int r)
{
	for(int c = 1; c < col; c++) {
		if(row[c] == r)
			return false;
	}

	return true;
}

ll f(int rooks, int col)
{
	if(col == n+1) {
		if(rooks == k) return 1;
		else return 0;
	}
	if(k-rooks > n-col+1) return 0;

	ll &ret = dp[rooks][col];
	if(ret != -1) return ret;

	ret = 0;
	ret += f(rooks, col+1);

	for(int r = 1; r <= n; r++) {
		if(check(col, r)) {
			row[col] = r;
			ret += f(rooks+1, col+1);
		}
	}

	return ret;
}

int main()
{
	int test;
	scanf("%d", &test);

	for(int t = 1; t <= test; t++) {
		scanf("%d %d", &n, &k);

		memset(row, 0, sizeof row);
		memset(dp, -1, sizeof dp);

		ans = f(0, 1);

		printf("Case %d: %lld\n", t, ans);
	}
}
