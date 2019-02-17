#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define MX 100005
#define mod 100000007
#define inf 0x3f3f3f3f
#define pi acos(-1)
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<ll, ll>

int l, h, dp[MX][2];
vector <int> v, seq;

int f(int pos, int tf, int pf)
{
	if(pos == h) return tf|pf;


	int &ret = dp[pos][tf];
	if(ret != -1) return ret;

	ret = 0;

	int lmt;

	if(tf) lmt = 0;
	else lmt = v[pos];

	for(int dgt = lmt; dgt <= 9; dgt++) {
		int nf = tf, mf = pf;
		if(!tf && dgt > lmt) nf = 1;
		if(dgt > v[l-pos-1]) mf = 1;
		if(pf && !tf && dgt < v[l-pos-1]) mf = 0;

		seq.pb(dgt);
		ret |= f(pos+1, nf, mf);

		if(ret) break;
		seq.pop_back();
	}

	return ret;
}

int solve(string s)
{
	v.clear();
	seq.clear();

	l = s.size(), h = l/2 + (l%2);
	for(int i = 0; i < l; i++) {
		v.pb(s[i]-'0');
	}

	return f(0, 0, 0);
}

int main()
{
	int test;
	scanf("%d", &test);

	int ans;
	string s;
	for(int t = 1; t <= test; t++) {
		cin>>s;

		memset(dp, -1, sizeof dp);

		ans = solve(s);

		printf("Case %d: ", t);
		if(ans) {
			h = l-h;
			for(auto a : seq) cout<<a;
			for(int i = h-1; i >= 0; i--) cout<<seq[i];
			cout<<endl;
		}
		else {
			cout<<1;
			for(int i = 0; i < l-1; i++) cout<<0;
			cout<<1<<endl;
		}
	}
}
