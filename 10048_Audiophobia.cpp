#include<cstdio>
#include<algorithm>
#define SIZE 110
#define INF 1000000000
using namespace std;
int matrix[SIZE][SIZE];

int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int c, s, q, c1, c2, d, counter = 0;
	while(scanf("%d %d %d", &c, &s, &q) && (c || s || q)){
		if(counter > 0)printf("\n");
		for(int i = 0; i < SIZE; ++i){
			for(int j = 0; j < SIZE; ++j){
				matrix[i][j] = INF;
			}
		}
		for(int i = 0; i < s; ++i){
			scanf("%d %d %d", &c1, &c2, &d);
			matrix[c1][c2] = d;
			matrix[c2][c1] = d;
		}
		
		for(int k = 0; k < SIZE; ++k){
			for(int i = 0; i < SIZE; ++i){
				for(int j = 0; j < SIZE; ++j){
					matrix[i][j] = min(matrix[i][j], max(matrix[i][k], matrix[k][j]));
				}
			}
		}
		
		printf("Case #%d\n", ++counter);
		for(int i = 0; i < q; ++i){
			scanf("%d %d", &c1, &c2);
			if(matrix[c1][c2] == INF){
				printf("no path\n");
			}
			else{
				printf("%d\n", matrix[c1][c2]);
			}
		}
		
		
	}
	return 0;
}