#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//dfs
#define MX 1099
int n, r, no, c, sx, sy, dx, dy;
bool vis[MX][MX];
int level[MX][MX];
int d1[] = {1, -1, 0, 0};
int d2[] = {0, 0, 1, -1};

int main()
{
    int row, col;
    while(cin>>row>>col && row+col) {
        cin>>n;
        while(n--) {
            cin>>r>>no;
            while(no--) {
                cin>>c;
                vis[r][c] = 1;
            }
        }
        cin>>sx>>sy>>dx>>dy;

        queue <pair<int, int> > q;
        q.push(make_pair(sx, sy));
        vis[sx][sy] = 1;

        while(!q.empty()) {
            pair <int, int> xy = q.front();
            q.pop();
            for(int i = 0; i < 4; i++) {
                int rx = xy.first+d1[i], ry = xy.second+d2[i];
                if(rx < 0 || rx >= row || ry < 0 || ry >= col) continue;
                if(!vis[rx][ry]) {
                    q.push(make_pair(rx, ry));
                    vis[rx][ry] = 1;
                    level[rx][ry] = level[xy.first][xy.second]+1;
                    if(dx == rx && dy == ry) goto END;
                }
            }
        }

        END:
        cout<<level[dx][dy]<<endl;
        //clearing
        memset(vis, 0, sizeof vis);
        memset(level, 0, sizeof level);
    }
}
