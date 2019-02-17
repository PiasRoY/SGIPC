#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MX 1005
#define mod 100000007
#define inf 0x3f3f3f3f
#define pi acos(-1)
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define pii pair<int, int>

int n, e;
int dp[MX][2], par[MX];
vector <int> edges[MX];

int f(int u, int isKilled)
{
    int& ret = dp[u][isKilled];
    if(ret != -1) return ret;

	if(edges[u].empty()) return ret = 1;

    ret = 0;
    for(int i = 0; i < edges[u].size(); i++) {
        int v = edges[u][i];

        if(par[u] != v) {
			par[v] = u;

            if(isKilled == 0) {
				ret += max(f(v, 0), f(v, 1));
            }
            else {
                ret += f(v, 0);
            }
        }
    }

    return ret += isKilled;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

    int test;
    scanf("%d", &test);

    int u, v;
    for(int t = 1; t <= test; t++) {
        scanf("%d %d", &n, &e);

        for(int i = 0; i < e; i++) {
            scanf("%d %d", &u, &v);
            edges[u].pb(v);
            edges[v].pb(u);
        }

        memset(dp, -1, sizeof dp);
        for(int i = 1; i <= n; i++) par[i] = i;

        int ans = 0;
        for(int i = 1; i <= n; i++) {
			if(dp[i][0] == -1)
				ans += max(f(i, 0), f(i, 1));
        }

        printf("Case %d: %d\n", t, ans);

        //clearing
        for(int i = 0; i <= n; i++)
			edges[i].clear();
    }
}
