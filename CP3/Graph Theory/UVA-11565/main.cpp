#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x, y, z, a, b, c, test;
	scanf("%d", &test);

	for(int t = 1; t <= test; t++) {
		scanf("%d %d %d", &a, &b, &c);

		bool tf = false;
		for(x = -100; x <= 100; x++) {
			for(y = -100; y <= 100; y++) {
				for(z = -100; z <= 100; z++) {
					if(x != y && y != z && z != x && x+y+z == a && x*y*z == b && x*x+y*y+z*z == c) {
						if(!tf) {
							tf = true;
							printf("%d %d %d\n", x, y, z);
							goto last;
						}
					}
				}
			}
		}

		last:
			if(!tf) printf("No solution.\n");
	}
}
