#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//dfs
vector <int> edges[100];
int domi[100][100];
int m;

void dfs(int node)
{
    if(domi[m][node]) return;
    domi[m][node] = 1;
    // cout<<node<<endl;
    for(int i = 0; i < edges[node].size(); i++) {
        int n = edges[node][i];
        if(!domi[m][n]) {
            dfs(n);
        }
    }
}

int main()
{
    int test;
    cin>>test;
    for(int t = 1; t <= test; t++) {
        int nodes, x, mx = 0;
        cin>>nodes;
        for(int i = 0; i < nodes; i++) {
            for(int j = 0; j < nodes; j++) {
                cin>>x;
                if(x) edges[i].push_back(j);
            }
        }

        for(int i = 0; i < nodes; i++) {
            if(i != 0) domi[i][i] = 1;
            m = i;
            dfs(0);
            if(i != 0) domi[i][i] = 0;
        }

        string str = "+";
        for(int i = 0; i < (2*nodes)-1; i++) str += "-";
        str += "+";
        printf("Case %d:\n", t);
        for(int i = 0; i < nodes; i++) {
            cout<<str<<endl<<"|";
            for(int j = 0; j < nodes; j++) {
                if(i == 0 && domi[0][j]) printf("Y|");
                else if(!domi[i][j] && domi[0][j]) printf("Y|");
                else printf("N|");
            }
            cout<<endl;
        }
        cout<<str<<endl;

        //clearing
        for(int i = 0; i < 100; i++) {
            edges[i].clear();
            for(int j = 0; j < 100; j++) {
                domi[i][j] = 0;
            }
        }
    }
}
