#include <cstdio>
#include <cstring>
using namespace std;
int solution[1010];
int guess[1010];
bool solution_taken[1010];
bool guess_taken[1010];
int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int N;
	int counter = 0;
	while(scanf("%d", &N) == 1 && N > 0){
		for(int i = 0; i < N; ++i){
			scanf("%d", &solution[i]);
		}
		printf("Game %d:\n", ++counter);
		do{
			for(int i = 0; i < N; ++i){
				scanf("%d", &guess[i]);
			}
			if(guess[0] > 0){
				int strong = 0, weak = 0;
				memset(solution_taken, false, sizeof(solution_taken));
				memset(guess_taken, false, sizeof(guess_taken));
				for(int i = 0; i < N; ++i){
					if(guess[i] == solution[i]){
						solution_taken[i]=true;
						guess_taken[i] = true;
						strong++;
					}
				}
				for(int i = 0; i < N; ++i){
					for(int j = 0; j < N; ++j){
						if(guess[i] == solution[j] && solution_taken[j] == false && guess_taken[i] == false){
							++weak;
							solution_taken[j]=true;
							guess_taken[i] = true;
						}
					}
				}
				printf("    (%d,%d)\n", strong, weak);
			}
		}while(guess[0] > 0);
	}
	
	return 0;
}