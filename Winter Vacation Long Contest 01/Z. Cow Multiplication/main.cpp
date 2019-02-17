#include <iostream>
#include <string>
using namespace std;

typedef long long ll;
#define MX 100005
#define mod 100000007
#define inf 0x3f3f3f3f
#define pi acos(-1)
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define pii pair<int, int>

int main()
{
	string s, t;
	cin>>s>>t;

	ll x, y, ans = 0;

	for(int i = 0; i < t.size(); i++) {
		for(int j = 0; j < s.size(); j++) {
			x = t[i]-'0';
			y = s[j]-'0';

			ans += (x*y);
		}
	}

	printf("%lld\n", ans);
}
