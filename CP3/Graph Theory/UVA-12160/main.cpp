#include <bits/stdc++.h>
using namespace std;

int main()
{
    int L, U, R, t = 1, TF;
    while(cin>>L>>U>>R && L+U+R)
    {
        vector <int> key;
        int vis[10005] = {0}, level[10005] = {0};

        for(int i = 0; i < R; i++)
        {
            int x;
            cin>>x;
            key.push_back(x);
        }

        queue <int> q;
        q.push(L);
        vis[L] = 1;
        TF = 0;

        while(!q.empty()) {
            int a = q.front();
            q.pop();
            if(a == U) {TF=1; break;}
            for(int i = 0; i < R; i++) {
                int nxt = (a+key[i])%10000;
                if(!vis[nxt]) {
                    vis[nxt] = 1;
                    level[nxt] = level[a]+1;
                    q.push(nxt);
                }
            }
        }

        if(!TF) printf("Case %d: Permanently Locked\n", t++);
        else printf("Case %d: %d\n", t++, level[U]);
    }
}
