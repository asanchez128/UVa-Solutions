#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
int matrix[25][25];
#define INF 100000
int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int m;
	int number;
	int queries;
	int tc = 0;
	while(true){
		for(int i = 1; i <= 20; ++i){
			for(int j = 1; j <= 20; ++j){
				matrix[i][j] = INF;
			}
		}
		for(int i = 1; i <= 19; ++i){
			if(i == 1){
				if(scanf("%d", &m) != 1){
					exit(0);
				}
				else{
					printf("Test Set #%d\n", ++tc);
				}
			}
			else{
				scanf("%d", &m);
			}
			for(int j = 0; j < m; ++j){
				scanf("%d", &number);
				matrix[i][number]=1;
				matrix[number][i]=1;
			}
		}
		
		for(int k = 1; k <= 20; ++k){
			for(int i = 1; i <= 20; ++i){
				for(int j = 1; j <= 20; ++j){
					if(matrix[i][k] + matrix[k][j] < matrix[i][j])
					matrix[i][j] = matrix[i][k] + matrix[k][j];
				}
			}
		}
		scanf("%d", &queries);
		int x, y;
		for(int i = 0; i < queries; ++i){
			scanf("%d %d", &x, &y);
			printf("%2d to %2d: %-d\n", x, y, matrix[x][y]);
		}
		printf("\n");
	}
	return 0;
}