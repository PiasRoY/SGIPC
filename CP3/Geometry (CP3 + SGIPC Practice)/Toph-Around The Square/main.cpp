#include <bits/stdc++.h>
using namespace std;

const double pi = acos(-1);

int main()
{
	int a, r1, r2, r3, r4;

	while(scanf("%d %d %d %d %d", &a, &r1, &r2, &r3, &r4) != EOF) {
		double ans = (a*a) - (pi/4) * ((r1*r1)+(r2*r2)+(r3*r3)+(r4*r4));

		printf("%.3f\n", ans);
	}
}
