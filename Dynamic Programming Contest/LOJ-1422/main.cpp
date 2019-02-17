#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MX 105
#define mod 100000007
#define inf 0x3f3f3f3f
#define pi acos(-1)
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define pii pair<int, int>

int cs[MX], dp[MX][MX];

int main()
{
	int test;
	cin>>test;

	int n;
	for(int t = 1; t <= test; t++) {
		cin>>n;

		for(int i = 1; i <= n; i++) cin>>cs[i];

		memset(dp, 0, sizeof dp);

		for(int i = 1; i <= n; i++) dp[i][i] = 1;

		int len, l, r, k;
		for(len = 2; len <= n; len++) {
			for(l = 1; l <= n; l++) {
				r = l+len-1;

				dp[l][r] = 1 + dp[l+1][r];

				for(k = l+1; k <= r; k++) {
					if(cs[l] == cs[k]) {
						dp[l][r] = min(dp[l][r], dp[l][k-1] + dp[k+1][r]);
					}
				}
			}
		}

		printf("Case %d: %d\n", t, dp[1][n]);
	}
}
