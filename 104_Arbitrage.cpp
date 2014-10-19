// Status: Accepted
#include<cstdio>
#include<algorithm>
#include <cstring>
using namespace std;
int N;

double dp[25][25][25];
int parent[25][25][25];

void printSol(int i, int j, int level){
	if(level == 0){
		printf("%d", i);
	}
	else{
		printSol(i, parent[level][i][j], level - 1);
		printf(" %d", j);
	}
}
int main(){
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	while(scanf("%d", &N) == 1){
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= N; ++i){
			dp[1][i][i] = 1.00;
		}
		for(int i = 1; i <= N; ++i){
			for(int j = 1; j <= N; ++j){
				if(i != j){
					scanf("%lf", &dp[1][i][j]);
				}
			}
		}

		bool found = false;
		
		memset(parent, -1, sizeof(parent));
		for(int lenght = 2; !found && lenght <= N+1; ++lenght){
			for(int k = 1; !found && k <= N; ++k){
				for(int i = 1; !found && i <= N; ++i){
					for(int j = 1; !found && j <= N; ++j){
						if(dp[lenght][i][j] < dp[lenght-1][i][k] * dp[1][k][j]){
							dp[lenght][i][j] = dp[lenght-1][i][k] * dp[1][k][j];
							parent[lenght][i][j] = k;
							if(i == j && dp[lenght][i][j] > 1.01){
									found = true;
									printSol(i, parent[lenght][i][i], lenght - 1);
									printf(" %d\n", i);
							}
						}
					}
				}
			}
		}
		
		if(!found){
			printf("no arbitrage sequence exists\n");    
		}
		}

	return 0;
}