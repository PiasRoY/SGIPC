#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define MX 65
#define mod 100000007
#define inf 0x3f3f3f3f
#define pi acos(-1)
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<ll, ll>

int pre[20];

void precal()
{
	pre[1] = 10, pre[2] = 9;
	for(int i = 4; i <= 18; i+=2) {
		pre[i-1] = pre[i] = pre[i-2]*10;
	}

	for(int i = 2; i <= 18; i++)
		pre[i] += pre[i-1];
}

void check(string &s, string &t)
{
	if(s.size() < t.size()) return;
	if(s.size() > t.size()) {
		swap(s, t);
		return;
	}

	for(int i = 0; i < t.size(); i++) {
		if(s[i] < t[i]) return;
		if(s[i] > t[i]) {
			swap(s, t);
			return;
		}
	}
}

int isPalindrome(string &s)
{
	int l = 0, r = s.size()-1;
	while(l < r) {
		if(s[l] != s[r])
			return 0;
		l++, r--;
	}

	return 1;
}

int solve(string& s)
{
	int mul, l = s.size(), h, ans = pre[l-1];

	if(l == 1) return s[0]-'0'+1;

	h = (l/2) + (l%2);

	int i, j, cnt = 0;
	for(j = 0; j < h; j++) {
		if(j == 0) mul = s[j]-'1';
		else mul = s[j]-'0';

		for(i = j+1; mul > 0 && i < h; i++) {
			mul *= 10;
		}

		ans += mul;
	}

	bool tf = true;
	for(i = h-1, j = l-h; i >= 0; i--, j++) {
		if(s[i] < s[j]) break;
		else if(s[i] > s[j]) {
			tf = false;
			break;
		}
	}
	if(tf) ans++;

	return ans;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int test;
	scanf("%d", &test);

	int f, g;
	string a, b;

	precal();

	for(int t = 1; t <= test; t++) {
		cin>>a>>b;

		check(a, b);

		f = solve(a)-isPalindrome(a);
		g = solve(b);

		printf("Case %d: %d\n", t, g-f);
	}
}
