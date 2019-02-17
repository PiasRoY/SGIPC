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

int mat[MX][MX];

int main()
{
	int n, mx;

	scanf("%d", &n);

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			scanf("%d", &mat[i][j]);
			mat[i][j] = mat[i][j] + mat[i][j-1] + mat[i-1][j] - mat[i-1][j-1]; //cumulative sum matrix
		}
	}

	mx = 0;

	for(int i = 1; i <= n; i++) {
	for(int j = 1; j <= n; j++)
		for(int l = i; l <= n; l++) {
		for(int k = j; k <= n; k++)
			mx = max(mx, mat[l][k] - mat[i-1][k] - mat[l][j-1] + mat[i-1][j-1]);
		}
	}

	printf("%d\n", mx);
}
