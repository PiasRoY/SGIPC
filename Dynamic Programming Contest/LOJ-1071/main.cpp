#include <bits/stdc++.h>
using namespace std;

#define MX 105

int ans, n, m, mat[MX][MX], dp[2*MX][MX][MX];

int f(int step, int fr, int sr)
{
	if(step == n+m-1) return mat[n][m];  //  meeting endpoint
	if(step != 1 && fr == sr) return 0; //two path not intersecting

	int &ret = dp[step][fr][sr];
	if(ret != -1) return ret;

	int fc = step-fr+1, sc = step-sr+1;

	if(fr < n && sr < n) ret = max(ret, f(step+1, fr+1, sr+1));
	if(fr < n && sc < m) ret = max(ret, f(step+1, fr+1, sr));
	if(fc < m && sr < n) ret = max(ret, f(step+1, fr, sr+1));
	if(fc < m && sc < m) ret = max(ret, f(step+1, fr, sr));

	ret += mat[fr][fc] + mat[sr][sc];

	return ret;
}

int main()
{
	int test;
	scanf("%d", &test);

	for(int t = 1; t <= test; t++) {
		scanf("%d %d", &n, &m);

		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				scanf("%d", &mat[i][j]);
			}
		}

		memset(dp, -1, sizeof dp);

		ans = f(1, 1, 1);

		printf("Case %d: %d\n", t, ans-mat[1][1]);
	}
}
