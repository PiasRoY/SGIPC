#include <bits/stdc++.h>
using namespace std;

#define MX 25
string s;
int n;
char ans[MX];
bool mark[MX], adj[MX][MX], tf;
void dfs(int idx)
{
	if(idx == n) {
		tf = true;
		printf("%c", ans[0]);
		for(int i = 1; i < n; i++)
			printf(" %c", ans[i]);
		printf("\n");
		return;
	}

	int i, j;
	for(i = 0; i < n; i++) {
		if(!mark[i]) {
			for(j = 0; j < idx; j++) {
				if(adj[s[i]-'A'][ans[j]-'A'])
					return;
			}
			if(j == idx) {
				ans[idx] = s[i];
				mark[i] = true;
				dfs(idx+1);
				mark[i] = false;
			}
		}
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int test;
	scanf("%d", &test);

	getchar();
	string line;
	while(test--) {
		getchar();
		memset(adj, false, sizeof adj);
		getline(cin, line);

		stringstream ss;
		ss << line;

		s = "";
		while(ss>>line) s+=line;
		sort(s.begin(), s.end());
		n = s.size();

		getline(cin, line);
		ss.clear();
		ss << line;

		while(ss>>line) {
			adj[line[0]-'A'][line[2]-'A'] = true;
		}

		tf = false;
		dfs(0);
		if(!tf) printf("NO\n");
		if(test != 0) printf("\n");
	}
}

/*
3

A B F G
A<B B<F

A B F G
A<B B<F

A B C
A<B B<C C<A
*/
