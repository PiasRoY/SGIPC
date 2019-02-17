#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define MX 20
#define mod 100000007
#define inf 0x3f3f3f3f
#define pi acos(-1)
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<ll, ll>

int n, mat[MX][MX], dp[MX][1<<15+2];

bool check(int n, int pos)
{
	return (bool) (n & (1 << pos));
}

int SET(int n, int pos)
{
	return (n | (1 << pos));
}

int f(int pos, int mask)
{
	if(pos == n) return 0;

	int &ret = dp[pos][mask];
	if(ret != -1) return ret;

	for(int i = 0; i < n; i++) {
		if(!check(mask, i)) {
			ret = max(ret, mat[pos][i] + f(pos+1, SET(mask, i)));
		}
	}

	return ret;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int test;
	scanf("%d", &test);

	int ans;
	for(int t = 1; t <= test; t++) {
		scanf("%d", &n);

		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++)
				scanf("%d", &mat[i][j]);
		}

		memset(dp, -1, sizeof dp);

		ans = f(0, 0);

		printf("Case %d: %d\n", t, ans);
	}
}
