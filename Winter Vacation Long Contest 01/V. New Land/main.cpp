#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define MX 2005
#define mod 100000007
#define inf 0x3f3f3f3f
#define pi acos(-1)
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<ll, ll>

int n, m, ans, mat[MX][MX], sim[MX][MX];

void set_col()
{
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			if(mat[j][i] == 0) sim[j][i] = 1 + sim[j-1][i];
			else sim[j][i] = 0;
		}
	}
}

int solve()
{
	for(int i = 1; i <= m; i++) {
		for(int j = n; j >= 1; j--) {
			if(mat[j][i] == 0)
				sim[j][i] = min(sim[j][i-1], sim[j][i]);
		}
	}
}

void show()
{
	cout<<endl;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cout<<sim[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	int test;
	scanf("%d", &test);

	char ch;
	for(int t = 1; t <= test; t++) {
		scanf("%d %d", &n, &m);

		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				cin>>ch;
				mat[i][j] = ch-'0';
			}
		}

		set_col();
		show();
		ans = solve();
		show();

		printf("Case %d: %d\n", t, ans);
	}
}
