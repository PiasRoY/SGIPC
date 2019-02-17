#include <bits/stdc++.h>
using namespace std;

#define eps 1e-9
typedef long long coord_t; // coordinate type

class point
{
public:
    coord_t x, y;

    point() {x = y = 0.0;} //default constructor
    point(coord_t x, coord_t y) : x(x), y(y) {} //constructor

    bool operator <(const point &p) {
        if(fabs(x - p.x) > eps)
            return x < p.x;
        return y < p.y;
    }

    bool operator ==(point &p) const{
        return ((fabs(x - p.x) < eps) && (fabs(y - p.y) < eps));
    }
};

coord_t ccw(point& a, point& b, point& c) {
    return (b.y-a.y)*(c.x-b.x) - (b.x-a.x)*(c.y-b.y); // 0 = colinear, <0 = ccw, >0 = cw
}

vector <point> convexHull_MonotoneChain(vector<point>& P)
{
    int n = P.size(), k = 0;
    vector <point> H(2*n);

    sort(P.begin(), P.end());

    for(int i = 0; i < n; i++) {
        while(k >= 2 && ccw(H[k-2], H[k-1], P[i]) < 0) k--;
        H[k++] = P[i];
    }

    for(int i = n-2, t = k+1; i >= 0; i--) {
        while(k >= t && ccw(H[k-2], H[k-1], P[i]) < 0) k--;
        H[k++] = P[i];
    }

    H.resize(k);
    return H;
}

int main()
{
	int test;
	scanf("%d", &test);

	char ch;
	long long n, x, y;
	vector <point> points, CH;
	for(int t = 1; t <= test; t++) {
		scanf("%lld", &n);

		points.clear();
		while(n--) {
			scanf("%lld %lld %c", &x, &y, &ch);
			if(ch == 'Y') points.push_back(point(x, y));
		}

		CH = convexHull_MonotoneChain(points);

		printf("%d\n", CH.size()-1);
		for(int i = CH.size()-1; i >= 1; i--)
			printf("%lld %lld\n", CH[i].x, CH[i].y);
	}
}
