#include <cstdio>
#include <cstdlib>

using namespace std;
char a[35], b[35];
char * pEndA;
char * pEndB;

long int gcd(long int a, long int b){
	return b == 0 ? a: gcd(b, a % b);
}
int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	long int _a, _b;
	int N;
	scanf("%d\n", &N);
	for(int i = 0; i < N; ++i){
		fgets(a, 35, stdin);
		fgets(b, 35, stdin);
		_a = strtol(a, &pEndA, 2);
		_b = strtol(b, &pEndA, 2);
		// Strings which have only one digit are also invalid (it's another limitation).
		if(gcd(_a, _b) > 1){
			printf("Pair #%d: All you need is love!\n", i + 1);
		}
		else{
			printf("Pair #%d: Love is not all you need!\n", i+1);
		}
	}
	
	return 0;
}