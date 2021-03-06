#include <bits/stdc++.h>
using namespace std;

typedef double coord_t;

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

class vec //most of the vec is from CP3
{
public:
    coord_t x, y;

    vec() {x = y = 0.0;}
    vec(coord_t x, coord_t y) : x(x), y(y) {}
};

vec toVec(point a, point b) {
    return vec(b.x - a.x, b.y - a.y);
}

vec scale(vec v, double s) {
    return vec(v.x * s, v.y * s);
}

point translate(point p, vec v) {
    return point(p.x + v.x, p.y + v.y);
}

coord_t dot(vec a, vec b) {
    return (a.x*b.x + a.y*b.y);
}

coord_t norm_sq(vec v) {
    return v.x*v.x + v.y*v.y;
}

coord_t dist(point a, point b) //euclidean distance
{
    coord_t dx = a.x-b.x, dy = a.y-b.y;
    return sqrt(dx*dx + dy*dy);
}

coord_t distToLine(point a, point b, point p, point &c) //c = a + u * ab
{
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab); //didn't understand this formula.
    c = translate(a, scale(ab, u));

    return dist(p, c);
}

int main()
{
	point closest;

	double x = distToLine(point(0, 0), point(10, 0), point(5, 10), closest);

	cout<<closest.x<<" "<<closest.y<<endl;
	cout<<x<<endl;
}
