#include <cstdio>
#define debug false
using namespace std;
int main(){
	if (debug){
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	}

	int N, a, b, c, counter = 0;
	scanf("%d", &N);
	while (N--){
		printf("Case %d: ", ++counter);
		scanf("%d%d%d", &a, &b, &c);
		if (a <= 20 && b <= 20 && c <= 20){
			printf("good\n");
		}
		else{
			printf("bad\n");
		}
	}
	return 0;
}