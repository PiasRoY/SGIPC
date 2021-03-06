#include <bits/stdc++.h>
using namespace std;

#define eps 1e-9
typedef double coord_t;
typedef long long ll;

class point
{
public:
    coord_t x, y;

    point() {x = y = 0.0;} //default constructor
    point(coord_t x, coord_t y) : x(x), y(y) {} //constructor
};

coord_t dist(point a, point b) //euclidean distance
{
    coord_t dx = a.x-b.x, dy = a.y-b.y;
    return sqrt(dx*dx + dy*dy);
}

int main()
{
	int n, x, y, id;
	double d1, d2;

	while(scanf("%d", &n) && n) {
		vector <point> points;
		for(int i = 0; i < n; i++) {
			scanf("%d %d", &x, &y);
			points.push_back(point(x, y));
		}

		x = n/2;
		for(int i = 0; i < n; i++) {
			d1 = dist(points[i], points[(i+x)%n]);
			d2 = dist(points[i], points[(i+x+1)%n]);

			if(d1 > d2+eps) id = (i+x)%n;
			else id = (i+x+1)%n;

//			cout<<(i+x)%n<<" "<<(i+x+1)%n<<endl;
//			cout<<max(dist(points[i], points[(i+x)%n]), dist(points[i], points[(i+x+1)%n]))<<endl;
			printf("%lld\n", id+1);
		}
	}
}
