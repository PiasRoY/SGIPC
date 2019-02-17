#include <bits/stdc++.h>
using namespace std;

int main()
{
	bool tf;
	int n, abcde, fghij, tmp, used, test = 1;

	while(scanf("%d", &n) && n)
	{
		if(test++ != 1) printf("\n");
		tf = false;

		for(int fghij = 1234; fghij <= 98765; fghij++) {
			abcde = fghij * n;
			if(abcde > 98765) continue;

			used = (fghij < 10000);
			tmp = abcde;

			while(tmp)
			{
				used |= 1 << (tmp % 10);
				tmp /= 10;
			}

			tmp = fghij;
			while(tmp)
			{
				used |= 1 << (tmp % 10);
				tmp /= 10;
			}

			if(used == (1<<10)-1) {
				tf = true;
				printf("%0.5d / %0.5d = %d\n", abcde, fghij, n);
			}
		}

		if(!tf)
			printf("There are no solutions for %d.\n", n);
	}
}
