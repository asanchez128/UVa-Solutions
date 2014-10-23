#include <cstdio>

using namespace std;

int _min = 1000010;
int numbers[10010];
int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int N, M;
	int a, b;
	int answer1, answer2;
	while(scanf("%d\n", &N) == 1){
		_min = 1000010;
		for(int i = 0; i < N; ++i){
			scanf("%d", &numbers[i]);
		}
		scanf("%d", &M);
		
		for(int i = 0; i < N - 1; ++i){
			for(int j = i + 1; j < N; ++j){			
				a = numbers[i];
				b = numbers[j];
				
				if(a + b == M){
					if(a > b){
						if(a - b < _min){
							answer1 = b;
							answer2 = a;
							_min = a - b;
						}
					}
					else{
						if(b - a < _min){
							answer1 = a;
							answer2 = b;
							_min = b - a;
						}
					}
				}
			}
				
		}
		printf("Peter should buy books whose prices are %d and %d.\n\n", answer1, answer2);
	}
	return 0;
}