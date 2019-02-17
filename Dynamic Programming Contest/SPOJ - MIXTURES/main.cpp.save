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
#define pii pair<int, int

int con[MX], dp[MX][MX];

int main()
{
	int n, len, l, r, x, y, k;

	while(scanf("%d", &n) != EOF)
	{
		for(int i = 1; i <= n; i++) scanf("%d", &con[i]);

		for(int i = 2; i <= n; i++) con[i] = con[i] + con[i-1];

		for(int i = 1; i <= n; i++)
			for(int j = i+1; j <= n; j++)
				dp[i][j] = inf;

		for(len = 2; len <= n; len++) {
			for(l = 1; l <= n-len+1; l++) {
				r = l+len-1;

				for(k = l; k < r; k++) {
					x = (con[k] - con[l-1]) % 100;
					y = (con[r] - con[k]) % 100;

					dp[l][r] = min(dp[l][r], dp[l][k]+dp[k+1][r]+x*y);
				}
			}
		}

		printf("%d\n", dp[1][n]);
	}
}
