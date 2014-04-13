#include<cstdio>
#include<cstring>
#define SIZE 120
using namespace std;
char today[SIZE][SIZE];
char tomorrow[SIZE][SIZE];
int dr[] = {-1,  0, 0, 1};
int dc[] = { 0, -1, 1, 0};

void moveTomorrowToToday(int r, int c){
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			today[i][j] = tomorrow[i][j];
		}
	}
}

bool valid(int newR, int newC, int r, int c){
	if(newR < 0 || newR >= r || newC < 0 || newC >= c) return false;
	return true;
}

void fight(int r, int c){
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			char myCell = today[i][j];
			bool found = false;
			for(int k = 0; k < 4 && !found; k++){
				int newR = i + dr[k];
				int newC = j + dc[k];
				
				if(valid(newR, newC, r, c)){
					char neighbor = today[newR][newC];
					if(myCell == 'R' && neighbor == 'P'){
						tomorrow[i][j] = 'P';
						found = true;
					}else if(myCell == 'P' && neighbor == 'S'){
						tomorrow[i][j] = 'S';
						found = true;
					} else if(myCell == 'S' && neighbor == 'R'){
						tomorrow[i][j] = 'R';
						found = true;
					} 
				}
			}
			if(!found){
						tomorrow[i][j] = myCell;
			}
		}
	}	
}
void simulation(int r, int c, int n){
	for(int i = 0; i < n; ++i){
		fight(r, c);
		moveTomorrowToToday(r, c);
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("IN.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int tc, r, c, n;
	scanf("%d\n", &tc);
	for(int i = 0; i < tc; ++i){
		if(i > 0) printf("\n");
		scanf("%d %d %d\n", &r, &c, &n);
		for(int j = 0; j < r; ++j){
			for(int k = 0; k < c ; ++k){
				today[j][k] = getchar();
			}
			getchar();
		}
		simulation(r, c, n);
		for(int p = 0; p < r; ++ p){
			for(int q = 0; q < c; ++q){
				printf("%c", tomorrow[p][q]);
			}
			printf("\n");
		}
		
	}
}