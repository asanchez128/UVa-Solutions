// Status: accepted
// author: sanmar1
#include <cstdio>
#include <cmath>
#include <complex>
#define debug false
#define x real()
#define y imag()

using namespace std;
typedef complex<double> PT;

int main(){
	if (debug){
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	}

	int N;
	double a, b, c, d, w, z;
	bool found = false;
	
	while (scanf("%d", &N) == 1){
		found = false;
		scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
		PT gopher(a,b); 
		PT dog(c, d);
		for (int i = 0; i < N; ++i){
			scanf("%lf%lf", &w, &z);
			if (found == false){
				PT hole(w, z);
				if (hypot(dog.x - hole.x, dog.y - hole.y)  >= hypot(gopher.x - hole.x, gopher.y - hole.y)*2.0){
					found = true;
					printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n", hole.x, hole.y);
				}
			}
		}
		if (found == false){
			printf("The gopher cannot escape.\n");
		}
	}
	return 0;
}