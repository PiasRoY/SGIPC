#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MX 20
#define mod 100000007
#define inf 0x3f3f3f3f
#define pi acos(-1)
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define pii pair<int, int>

int n, m, w, sum, ans, node[MX], mat[MX][MX], dp[1<<16][16];
vector <int> odd_vertices;

void find_odd()
{
	for(int i = 1; i <= n; i++)
		if(node[i] % 2)
			odd_vertices.pb(i);
}

void floyd_reset()
{
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(i == j) mat[i][j] = 0;
			else mat[i][j] = inf;
		}
	}
}

void floyd_warshall()
{
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
			}
		}
	}
}

int perfect_matching(int mask, int prev)
{
	if(mask == (1<<odd_vertices.size())-1) return 0;

	int &ret = dp[mask][prev];
	if(ret != -1) return ret;

	int ans;
	ret = inf;

	for(int i = 0; i < odd_vertices.size(); i++) {
		if((mask & (1<<i)) == 0) {
			ans = perfect_matching(mask | (1<<i), odd_vertices[i]);

			if(__builtin_popcount(mask) % 2)
				ans += mat[prev][odd_vertices[i]];

			ret = min(ret, ans);
		}
	}

	return ret;
}

int main()
{
	int test;
	scanf("%d", &test);

	int u, v, w;
	for(int t = 1; t <= test; t++) {
		scanf("%d %d", &n, &m);

		floyd_reset();
		memset(node, 0, sizeof node);

		sum = 0;
		for(int i = 0; i < m; i++) {
			scanf("%d %d %d", &u, &v, &w);
			mat[u][v] = min(mat[u][v], w);
			mat[v][u] = min(mat[v][u], w);
			node[u]++;
			node[v]++;
			sum += w;
		}

		find_odd();
		floyd_warshall();

		memset(dp, -1, sizeof dp);

		ans = sum + perfect_matching(0, 0);

		printf("Case %d: %d\n", t, ans);

		//clearing
		odd_vertices.clear();
	}
}
