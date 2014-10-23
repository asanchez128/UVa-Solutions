#include <cstdio>
using namespace std;
int main(){
	int N;
	int e, f, c;
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%d %d %d", &e, &f, &c);
		int bottles = e + f;
		int counter = 0;
		while(bottles > 0){
			bottles-=c;
			if(bottles >= 0){
				++counter;
				bottles++;	
			}
		}
		printf("%d\n", counter);
	}
	return 0;
}