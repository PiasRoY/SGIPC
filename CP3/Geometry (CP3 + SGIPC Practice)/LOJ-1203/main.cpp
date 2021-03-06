#include <bits/stdc++.h>
using namespace std;

#define eps 1e-9
const double PI = acos(-1);
typedef double coord_t; // coordinate type

class point
{
public:
    coord_t x, y;

    point() {x = y = 0.0;} //default constructor
    point(coord_t x, coord_t y) : x(x), y(y) {} //constructor

    bool operator <(const point &p) {
    	return x < p.x || (x == p.x && y < p.y);
    }
};

coord_t ccw(point& a, point& b, point& c)
{
    return (b.y-a.y)*(c.x-b.x) - (b.x-a.x)*(c.y-b.y); // 0 = colinear, <0 = ccw, >0 = cw
}

vector <point> convexHull_MonotoneChain(vector<point>& P)
{
    int n = P.size(), k = 0;
    vector <point> H(2*n);

    sort(P.begin(), P.end());

    for(int i = 0; i < n; i++) {
        while(k >= 2 && ccw(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }

    for(int i = n-2, t = k+1; i >= 0; i--) {
        while(k >= t && ccw(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }

    H.resize(k);
    return H;
}

class vec //most of the vec is from CP3
{
public:
    coord_t x, y;

    vec() {x = y = 0.0;} //default constructor
    vec(coord_t x, coord_t y) : x(x), y(y) {} //constructor
};

coord_t dot(vec a, vec b) {
    return (a.x*b.x + a.y*b.y);
}

coord_t norm_sq(vec v) {
    return v.x*v.x + v.y*v.y;
}

vec toVec(point a, point b) {
    return vec(b.x - a.x, b.y - a.y);
}

coord_t angle(point a, point o, point b) { //angle <aob
    vec oa = toVec(o, a), ob = toVec(o, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

int main()
{
    int test;
    scanf("%d", &test);

    int n, x, y;
    vector <point> points, CH;

    for(int t = 1; t <= test; t++) {
		scanf("%d", &n);

		points.clear();
		for(int i = 0; i < n; i++) {
			scanf("%d %d", &x, &y);
			points.push_back(point(x, y));
		}

		CH = convexHull_MonotoneChain(points);

		double tang, ang = (CH.size() > 2) ? angle(CH[CH.size()-2], CH[0], CH[1]) : 0;

		for(int i = 1; i < CH.size()-1; i++) {
			tang = angle(CH[i-1], CH[i], CH[i+1]);

			if(tang+eps < ang) ang = tang;
		}

		ang *= 180 / PI;

		if(isnan(ang)) printf("Case %d: 0\n", t);
		else printf("Case %d: %.8f\n", t, ang);
    }
}
