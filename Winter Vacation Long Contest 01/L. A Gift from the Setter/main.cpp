#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define MX 100005
#define mod 1000007
#define inf 100000000000
#define pi acos(-1)
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair <double, double>

ull k, c, n, ans, sum, x, temp, co;
ull a[MX], cum[MX];

int main()
{
	int test;
	cin>>test;

	for(int t = 1; t <= test; t++) {
		cin>>k>>c>>n>>a[0];

		for(int i = 1; i < n; i++) {
			temp = (a[i-1] * k) % mod;

			a[i] = (temp + c) % mod;
			cum[i] = a[i] + cum[i-1];
		}

		sum = 0, x = n-1;
		for(int i = 0; i < n; i++, x--) {
			temp = x * a[i];
			co = cum[n-1]-cum[i];

			sum += abs(temp-co);
		}

		printf("Case %d: %llu\n", t, sum);
	}
}
