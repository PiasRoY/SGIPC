#include <bits/stdc++.h>
using namespace std;

int main()
{
	int test;
	scanf("%d", &test);

	int s;
	while(test--) {
		scanf("%d", &s);

		printf("%.9f\n", 3*sqrt(3)*s*s/2);
	}
}
