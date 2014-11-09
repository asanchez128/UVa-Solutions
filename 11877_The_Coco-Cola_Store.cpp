#include <cstdio>
#include <cstdlib>
int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int emptyBottles;
	while(scanf("%d", &emptyBottles)){
		if(emptyBottles <= 0)exit(0);
		int cokeBottles = 0;
		while(emptyBottles > 1){
			if(emptyBottles == 2){
				emptyBottles++;
			}
			int result = (emptyBottles/3);
			int residuo = (emptyBottles % 3);
			cokeBottles += result;
			emptyBottles = result + residuo;
		}
		printf("%d\n", cokeBottles);
	}
	return 0;
}