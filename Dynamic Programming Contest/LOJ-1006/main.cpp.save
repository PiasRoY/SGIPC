#include <bits/stdc++.h>
using namespace std;

#define MX 10005
#define mod 10000007
typedef long long ll;

int dp[MX];

int fn(int n)
{
	if(dp[n] != -1) return dp[n];

	return dp[n] = (fn(n-1) % mod + fn(n-2) % mod + fn(n-3) % mod + fn(n-4) % mod + fn(n-5) % mod + fn(n-6) % mod) % mod;
}

int main()
{
	int n, test;
	cin>>test;

	for(int t = 1; t <= test; t++) {
		memset(dp, -1, sizeof dp);

		for(int i = 0; i < 6; i++) cin>>dp[i];
		cin>>n;

		cout<<"Case "<<t<<": "<<fn(n) % mod<<endl;
	}
}
