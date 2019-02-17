#include <bits/stdc++.h>
using namespace std;

int main()
{
	int test;
	scanf("%d", &test);

	int n;
	pair <int, int> points[105];
	for(int t = 1; t <= test; t++) {
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			scanf("%d %d", &points[i].first, &points[i].second);

		long long mx = 0, dx, dy;
		for(int i = 0; i < n; i++) {
			for(int j = i+1; j < n; j++) {
				dx = points[i].first-points[j].first,
				dy = points[i].second-points[j].second;
				mx = max(mx, dx*dx+dy*dy);
			}
		}

		printf("Case %d: %lld\n", t, mx);
	}
}
