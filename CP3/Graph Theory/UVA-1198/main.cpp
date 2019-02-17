#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>
using namespace std;

typedef long long ll;
#define MX 50
#define inf 1e9
int mat[MX][MX], arr[MX];
long long path[MX][MX];

int setcount(ll n)
{
	int cnt = 0;
	while(n&1) {
		cnt++;
		n >>= 1;
	}

	return cnt;
}

void floyd(int n)
{
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				int temp = mat[i][k] + mat[k][j];

				if(temp < mat[i][j]) {
					mat[i][j] = temp;
				}
			}
		}
	}

	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(mat[i][j] == mat[i][k] + mat[k][j]) {
					path[i][j] |= ((ll)1<<(ll)(k-1));
				}
			}
		}
	}
}

void reset()
{
	for(int i = 0; i < MX; i++) {
		for(int j = 0; j < MX; j++) {
			if(i == j) mat[i][j] = 0;
			else mat[i][j] = inf;
			path[i][j] = 0;
		}
	}
}

int main()
{
	string line;
	int n, x, test;
	scanf("%d", &n);

	reset();
	cin.ignore();

	stringstream ss;
	for(int i = 1; i <= n; i++) {
		getline(cin, line);

		ss << line;
		while(ss>>x) {
			mat[i][x] = 1;
			mat[x][i] = 1;
		}

		ss.clear();
	}

	floyd(n);

	int q, k;
	scanf("%d", &q);

	cin.ignore();

	while(q--) {
		getline(cin, line);

		k = 0;

		ss << line;
		while(ss>>x) {
			arr[k++] = x;
		}
		ss.clear();

		long long ans = 0;
		for(int i = 0; i < k; i++) {
			for(int j = 0; j < k; j++) {
				ans |= (ll)path[arr[i]][arr[j]];
			}
		}

		if(setcount(ans) == n) printf("yes\n");
		else printf("no\n");
	}
}
