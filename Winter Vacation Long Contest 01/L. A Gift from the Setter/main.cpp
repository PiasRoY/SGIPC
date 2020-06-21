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

ll k, c, n, ans, sum, x;
ll a[MX], cum[MX];

int main()
{
	int test;
	cin>>test;

	for(int t = 1; t <= test; t++) {
		cin>>k>>c>>n>>a[0];

		for(int i = 1; i < n; i++) {
			a[i] = (((a[i-1] * k) % mod) + c) % mod;
		}

		sort(a, a+n);

		for(int i = 1; i < n; i++) {
			cum[i] = a[i] + cum[i-1];
		}

		sum = 0, x = n-1;
		for(int i = 0; i < n; i++, x--) {
			ll temp = x * a[i];
			ll co = cum[n-1]-cum[i];

			sum += abs(temp-co);
		}

		printf("Case %d: %lld\n", t, sum);
	}
}
