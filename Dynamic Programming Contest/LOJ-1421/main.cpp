#include <bits/stdc++.h>
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

int a[MX], incr[MX], decr[MX];

void lis(int n)
{
	int tail[n];

	tail[0] = a[0];
	int length = 1;

	for(int i = 0; i < n; i++) {
		if(a[i] > tail[length-1]) {
			tail[length++] = a[i];
			incr[i] = length;
		}
		else {
			auto it = lower_bound(tail, tail+length, a[i]);
			*it = a[i];
			incr[i] = it-tail+1;
		}
	}
}

void lds(int n)
{
	int tail[n];

	tail[0] = a[n-1];
	int length = 1;

	for(int i = n-1; i >= 0; i--) {
		if(a[i] > tail[length-1]) {
			tail[length++] = a[i];
			decr[i] = length;
		}
		else {
			auto it = lower_bound(tail, tail+length, a[i]);
			*it = a[i];
			decr[i] = it-tail+1;
		}
	}
}

int main()
{
	int test;
	cin>>test;

	int n;
	for(int t = 1; t <= test; t++) {
		cin>>n;

		for(int i = 0; i < n; i++) cin>>a[i];

		lis(n);
		lds(n);

		int mx = 0;
		for(int i = 0; i < n; i++) {
//			cout<<incr[i]<<" "<<decr[i]<<endl;
			mx = max(mx, min(incr[i], decr[i]));
		}

		printf("Case %d: %d\n", t, mx*2 - 1);
	}
}
