#include<cstdio>
#include<vector>
using namespace std;
struct point{
	double x, y;
	point(){
		x = 0, y = 0;
	}
	point(double _x, double _y){
		x = _x, y = _y;
	}

};

bool cmp(point i, point j){
	return i.x < j.x;
}
int main(){
	int t;
	int n;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		scanf("%d", &n);
		vector<point> vecPoints;
		double a, b;
		for(int j = 0; j < n; ++j){
			scanf("%lf%lf", &a, &b);
			point newPoint(a, b);
			vecPoints.push_back(newPoint);

		}	
	}
	return 0;
}