#include <cstdio>
#include <cmath>
#define EPS 1e-9
using namespace std;
	//double p, r, q, s, t, u;
	int p, r, q, s, t, u;
double f(double x){
	return p * exp(-x) + q * sin(x) + r* cos(x) + s * tan(x) + t * x * x + u;
}
	
double bisection(){
	double lo = 0.0, hi = 1.0;
	while(lo + EPS < hi){
		double x = (lo + hi)/2.0;
		if(f(lo) * f(x) <= 0)
		{
			hi = x;
		}
		else
		{
			lo = x;
		}
	}
	return lo;
	//return (lo + hi)/2.0;
}	

int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	//while(scanf("%lf %lf %lf %lf %lf %lf\n", &p, &q, &r, &s, &t, &u) == 6){
	while(scanf("%d%d%d%d%d%d", &p, &q, &r, &s, &t, &u) == 6){
		if(f(0) * f(1) > 0){
			printf("No solution\n");
		}
		else
		{
			printf("%.4f\n", bisection());
		}
	}
	return 0;
}
// #include<cmath>
// #include<cstdio>
 
// using namespace std;
 
// int p, q, r, s, t, u;
 
// float eval(float x) {
    // return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x  + u;
// }
 
// int main() {
	 // freopen("in.txt", "r", stdin);
	 // freopen("out.txt", "w", stdout);
    // while(scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) == 6) {
 
        // double low = 0.0f, mid = 0.5f, high = 1.0f, emid, ehigh;
        // while(high - low > 0.0000001f) {
            // mid = (low + high) / 2.0f;
            // emid = eval(mid), ehigh = eval(high);
            // if((ehigh < 0 && emid > 0) || \
                    // (ehigh >= 0 && emid > ehigh) || \
                    // (ehigh <= 0 && ehigh > emid)) {
                // low = mid;
            // } else {
                // high = mid;
            // }
        // }
 
        // if(abs(emid) <= 0.0001f)
            // printf("%1.4f\n", mid);
        // else
            // printf("No solution\n");
    // }
 
    // return 0;
// }