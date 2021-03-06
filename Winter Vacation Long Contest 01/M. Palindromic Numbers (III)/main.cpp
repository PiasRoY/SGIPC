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
#define pll pair<ll, ll

string s;
int solve(int l, int r)
{

	if(s[r] < s[l]) s[r] = s[l];
}

int main()
{
	int test;
	scanf("%d", &test);

	for(int t = 1; t <= test; t++) {
		cin>>s;

		tf = false;
		l = 0, r = s.size()-1;

		while(l < r) {
			if(s[r] < s[l]) s[r] = s[l], tf = true;
			else if(s[r] > s[l]) s[l]++, s[r] = s[l], tf = true;

			l++, r--;
		}

		if(!tf) {
			r = s.size()/2, l = r-1;

			if(s.size()%2) {
				if(s[r] < '9') s[r]++;
				else {
					s[r] = '0';
					for(r = r+1; l>=-1 && r <= s.size(); l--, r++) {
						if(l == -1) s[r-1] = '1', s = '1' + s;
						else if(s[l] == '9') s[l] = s[r] ='0';
						else {s[l]++, s[r]++; break;}
					}
				}
			}
			else {
				if(s[l] < '9') s[l]++, s[r]++;
				else {
					s[l] = s[r] = 0;
					for(l = l-1, r = r+1; l>=-1 && r <= s.size(); l--, r++) {
						if(l == -1) s[r-1] = '1', s = '1' + s;
						else if(s[l] == '9') s[l] = s[r] ='0';
						else {s[l]++, s[r]++; break;}
					}
				}
			}
		}

		printf("Case %d:", t);
		cout<<s<<endl;
	}
}
