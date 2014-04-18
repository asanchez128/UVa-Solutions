#include<cstdio>
#define SIZE 350
#include<algorithm>
using namespace std;
int grid[SIZE][SIZE];

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int tc, n;
	scanf("%d", &tc);
	for(int i = 0; i < tc; ++i){
		scanf("%d", &n);
		for(int j = 0; j < n; ++j){
			for(int k = 0; k < n; ++k){
				scanf("%d", &grid[j][k]);
				grid[j + n][k] = grid[j][k + n] = grid[j + n][k + n] = grid[j][k];
			}
		}
		/*for(int j = 0; j < 2*n; ++j){
			for(int k = 0; k < 2*n; ++k){
				printf("%d ", grid[j][k]);
			}
			printf("\n");
		}
		printf("\n\n");*/

		for(int j = 0; j < 2*n; ++j){
			for(int k = 0; k < 2*n; ++k){
				if(j > 0) grid[j][k] += grid[j-1][k] ;
				if(k > 0) grid[j][k] += grid[j][k - 1];
				if(j > 0 && k > 0) grid[j][k] -= grid[j - 1][k - 1];
			}
		}
		
		/*for(int j = 0; j < 2*n; ++j){
			for(int k = 0; k < 2*n; ++k){
				printf("%d ", grid[j][k]);
			}
			printf("\n");
		}
		printf("\n\n");*/


		int maxRect = -3e7;
		int subRect = maxRect;

		for(int j = 0; j < n; ++j) for(int k = 0; k < n; ++k)
			for(int l = j; l < n + j && l < 2*n; ++l) for(int m = k; m < n + k && m < 2*n; ++m){
				subRect = grid[l][m];
				if(j > 0) subRect -= grid[j-1][m];
				if(k > 0) subRect -= grid[l][k -1];
				if(j > 0 && k > 0) subRect += grid[j-1][k-1];
				maxRect = max(maxRect, subRect);
			}
		printf("%d\n", maxRect);

	}
	return 0;

}