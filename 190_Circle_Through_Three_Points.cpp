// Author: sanmar1
// Status: accepted
#include<cstdio>
#include<cmath>
#include<iostream>
#define EPS 1e-9
#define debug false

using namespace std;
struct point{
	double x, y;
	point(){ x = y = 0.0; }
	point(double _x, double _y){ x = _x, y = _y; }
	bool operator == (point other)const{
		return (fabs(x - other.x) < EPS && fabs(y - other.y) < EPS);
	}

};

void negative_zero(double &n){
	if (fabs(n) <= 1e-4){
		n = fabs(n);
	}
}

bool positive(double n){
	return (n >= 0.0);
}
struct line{
	double a, b, c;
};
void points_to_line(point p1, point p2, line &l) { 
	if (p1.x == p2.x) { 
		l.a = 1; 
		l.b = 0; 
		l.c = -p1.x; 
	} else {
		l.b = 1; 
		l.a = -(p1.y - p2.y) / (p1.x - p2.x); 
		l.c = -(l.a * p1.x) - (l.b * p1.y); 
	} 
}

void intersection_point(line l1, line l2, point &p){
	p.x = (l2.b*l1.c - l1.b*l2.c) / (l1.a*l2.b - l2.a*l1.b);
	//if (fabs(l1.b) > EPS) /* test for vertical line */ p.y = -(l1.a * (p.x) + l1.c) / l1.b; 
	//else p.y = -(l2.a * (p.x) + l2.c) / l2.b;
	p.y = (l1.a*l2.c - l2.a*l1.c) / (l1.a*l2.b - l2.a*l1.b);
}
int main(){
	if (debug){
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	}

	point a, b, c;
	while (scanf("%lf%lf%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y) == 6){
		line l1, l2;
		points_to_line(a, b, l1);
		points_to_line(a, c, l2);

		// 
		point midpoint_a_b(((a.x + b.x) / 2), ((a.y + b.y) / 2));
		point midpoint_a_c(((a.x + c.x) / 2), ((a.y + c.y) / 2));

		line perpl1, perpl2;
		perpl1.a = -l1.b;
		perpl1.b = l1.a;
		perpl1.c = (perpl1.a * midpoint_a_b.x + perpl1.b * midpoint_a_b.y);

		perpl2.a = -l2.b;
		perpl2.b = l2.a;
		perpl2.c = (perpl2.a * midpoint_a_c.x + perpl2.b * midpoint_a_c.y);

		point center;
		intersection_point(perpl1, perpl2, center);
		double radius = hypot(center.x - c.x, center.y - c.y);

		double _c, _d, _e;
		_c = center.x * -2.0;
		_d = center.y * -2.0;
		_e = center.x * center.x + center.y * center.y - radius * radius;
		cout << "(x";
		negative_zero(center.x);
		if (positive(center.x)){
			printf(" - %.3lf", center.x);
		}
		else{
			printf(" + %.3lf", fabs(center.x));
		}
		printf(")^2 + (y");
		negative_zero(center.y);
		if (positive(center.y)){
			printf(" - %.3lf", center.y);
		}
		else{
			printf(" + %.3lf", fabs(center.y));
		}
		printf(")^2 = ");
		printf("%.3lf^2\n", radius);

		printf("x^2 + y^2");
		negative_zero(_c);
		negative_zero(_d);
		negative_zero(_e);
		if (positive(_c)){
			printf(" + %.3lfx", _c);
		}
		else{
			printf(" - %.3lfx", fabs(_c));
		}
		if (positive(_d)){
			printf(" + %.3lfy", _d);
		}
		else{
			printf(" - %.3lfy", fabs(_d));
		}
		if (positive(_e)){
			printf(" + %.3lf", _e);
		}
		else{
			printf(" - %.3lf", fabs(_e));
		}

		printf(" = 0\n");
		printf("\n");
	}
	return 0;
}
