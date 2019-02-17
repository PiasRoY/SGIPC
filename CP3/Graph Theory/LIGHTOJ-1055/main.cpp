#include <bits/stdc++.h>
using namespace std;

#define MX 12
int N, X1, Y1, X2, Y2, X3, Y3, Dx1, Dy1, Dx2, Dy2, Dx3, Dy3;
int d1[] = {1, -1, 0, 0};
int d2[] = {0, 0, 1, -1};
bool vis[MX][MX][MX][MX][MX][MX];
int  dist[MX][MX][MX][MX][MX][MX];
bool grid[MX][MX];

class robot
{
public:
    int X1, Y1, X2, Y2, X3, Y3;
    robot (int x1, int y1, int x2, int y2, int x3, int y3) {
        X1 = x1, Y1 = y1, X2 = x2, Y2 = y2, X3 = x3, Y3 = y3;
    }

    bool operator == (robot X) {
        if(X1 == X.X1 && Y1 == X.Y1 && X2 == X.X2 && Y2 == X.Y2 && X3 == X.X3 && Y3 == X.Y3)
            return true;
        return false;
    }

    void out()
    {
    	cout<<X1<<" "<<Y1<<endl;
    	cout<<X2<<" "<<Y2<<endl;
    	cout<<X3<<" "<<Y3<<endl;
    	cout<<endl<<endl;
    }
};

void reset()
{
    for(int i = 0; i < MX; i++)
     for(int j = 0; j < MX; j++)
      for(int k = 0; k < MX; k++)
       for(int l = 0; l < MX; l++)
        for(int m = 0; m < MX; m++)
         for(int n = 0; n < MX; n++)
			vis[i][j][k][l][m][n] = false,
			dist[i][j][k][l][m][n] = -1;
}

void bfs(robot src)
{
    reset();

    queue <robot> q;
    vis[src.X1][src.Y1][src.X2][src.Y2][src.X3][src.Y3] = true;
    dist[src.X1][src.Y1][src.X2][src.Y2][src.X3][src.Y3] = 0;
    q.push(src);

    while(!q.empty()) {
        robot u = q.front();// u.out();
        q.pop();

        int d = dist[u.X1][u.Y1][u.X2][u.Y2][u.X3][u.Y3];
        for(int i = 0; i < 4; i++) {
            robot tp(u.X1+d1[i], u.Y1+d2[i], u.X2+d1[i], u.Y2+d2[i], u.X3+d1[i], u.Y3+d2[i]);

            //getting out range
            if(tp.X1 < 0 || tp.X1 >= N || tp.Y1 < 0 || tp.Y1 >= N) tp.X1 = u.X1, tp.Y1 = u.Y1;
            if(tp.X2 < 0 || tp.X2 >= N || tp.Y2 < 0 || tp.Y2 >= N) tp.X2 = u.X2, tp.Y2 = u.Y2;
            if(tp.X3 < 0 || tp.X3 >= N || tp.Y3 < 0 || tp.Y3 >= N) tp.X3 = u.X3, tp.Y3 = u.Y3;
            //stepping on obstacle
            if(grid[tp.X1][tp.Y1]) tp.X1 = u.X1, tp.Y1 = u.Y1;
            if(grid[tp.X2][tp.Y2]) tp.X2 = u.X2, tp.Y2 = u.Y2;
            if(grid[tp.X3][tp.Y3]) tp.X3 = u.X3, tp.Y3 = u.Y3;
            //overlapping
            if(tp.X1 == tp.X2 && tp.Y1 == tp.Y2) {
                if(tp.X1 == u.X1 && tp.Y1 == u.Y1) tp.X2 = u.X2, tp.Y2 = u.Y2;
                else if(tp.X2 == u.X2 && tp.Y2 == u.Y2) tp.X1 = u.X1, tp.Y1 = u.Y1;
            }
            if(tp.X1 == tp.X3 && tp.Y1 == tp.Y3) {
                if(tp.X1 == u.X1 && tp.Y1 == u.Y1) tp.X3 = u.X3, tp.Y3 = u.Y3;
                else if(tp.X3 == u.X3 && tp.Y3 == u.Y3) tp.X1 = u.X1, tp.Y1 = u.Y1;
            }
            if(tp.X1 == tp.X2 && tp.Y1 == tp.Y2) tp.X2 = u.X2, tp.Y2 = u.Y2;
            if(tp.X2 == tp.X3 && tp.Y2 == tp.Y3) {
                if(tp.X3 == u.X3 && tp.Y3 == u.Y3) tp.X2 = u.X2, tp.Y2 = u.Y2;
                else if(tp.X2 == u.X2 && tp.Y2 == u.Y2) tp.X3 = u.X3, tp.Y3 = u.Y3;
            }
            if(tp.X1 == tp.X2 && tp.Y1 == tp.Y2) tp.X1 = u.X1, tp.Y1 = u.Y1;
            if(tp.X1 == tp.X3 && tp.Y1 == tp.Y3) tp.X1 = u.X1, tp.Y1 = u.Y1;

			//visited
			if(!vis[tp.X1][tp.Y1][tp.X2][tp.Y2][tp.X3][tp.Y3]) {
                vis[tp.X1][tp.Y1][tp.X2][tp.Y2][tp.X3][tp.Y3] = true;
                dist[tp.X1][tp.Y1][tp.X2][tp.Y2][tp.X3][tp.Y3] = d + 1;
                q.push(tp);
			}
        }
    }
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int test;
    scanf("%d", &test);
    for(int t = 1; t <= test; t++) {
        scanf("%d", &N);
        getchar();

		int D = 1;
        char ch;
        memset(grid, false, sizeof grid);
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                scanf("%c", &ch);
                if(ch == '#') grid[i][j] = true;
                else if(ch == 'A') X1 = i, Y1 = j;
                else if(ch == 'B') X2 = i, Y2 = j;
                else if(ch == 'C') X3 = i, Y3 = j;
                else if(ch == 'X' && D == 1) Dx1 = i, Dy1 = j, D++;
                else if(ch == 'X' && D == 2) Dx2 = i, Dy2 = j, D++;
                else if(ch == 'X' && D == 3) Dx3 = i, Dy3 = j;
			}
			getchar();
        }

        robot src(X1, Y1, X2, Y2, X3, Y3);
        bfs(src);

        if(!vis[Dx1][Dy1][Dx2][Dy2][Dx3][Dy3] && !vis[Dx1][Dy1][Dx3][Dy3][Dx2][Dy2] &&
           !vis[Dx2][Dy2][Dx1][Dy1][Dx3][Dy3] && !vis[Dx2][Dy2][Dx3][Dy3][Dx1][Dy1] &&
           !vis[Dx3][Dy3][Dx1][Dy1][Dx2][Dy2] && !vis[Dx3][Dy3][Dx2][Dy2][Dx1][Dy1]) printf("Case %d: trapped\n", t);
        else {
            int mn = INT_MAX;
            if(vis[Dx1][Dy1][Dx2][Dy2][Dx3][Dy3]) mn = min(mn, dist[Dx1][Dy1][Dx2][Dy2][Dx3][Dy3]);
            if(vis[Dx1][Dy1][Dx3][Dy3][Dx2][Dy2]) mn = min(mn, dist[Dx1][Dy1][Dx3][Dy3][Dx2][Dy2]);
            if(vis[Dx2][Dy2][Dx1][Dy1][Dx3][Dy3]) mn = min(mn, dist[Dx2][Dy2][Dx1][Dy1][Dx3][Dy3]);
            if(vis[Dx2][Dy2][Dx3][Dy3][Dx1][Dy1]) mn = min(mn, dist[Dx2][Dy2][Dx3][Dy3][Dx1][Dy1]);
            if(vis[Dx3][Dy3][Dx1][Dy1][Dx2][Dy2]) mn = min(mn, dist[Dx3][Dy3][Dx1][Dy1][Dx2][Dy2]);
            if(vis[Dx3][Dy3][Dx2][Dy2][Dx1][Dy1]) mn = min(mn, dist[Dx3][Dy3][Dx2][Dy2][Dx1][Dy1]);

            printf("Case %d: %d\n", t, mn);
        }
    }
}
