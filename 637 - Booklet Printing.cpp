#include<cstdio>
#include<cmath>
#define SIZE 100
using namespace std;
int left[SIZE];
int right[SIZE];
int main(){
#ifndef ONLINE_JUDGE
	freopen("Text.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n;
	while(scanf("%d", &n)==1 && n > 0){
		printf("Printing order for %d pages:\n", n);
		int numberPages = (int)ceil((double)n/4);

		if(n == 1){
			printf("Sheet 1, front: Blank, 1\n");
		}
		else{
			int page = 0;
			for(int i = 1; i <= numberPages * 2; ++i){
				if(i % 2 == 1){
					++page;
					right[i]=page;
				}
				else{
					++page;
					left[i]=page;				
				}
			}

			for(int i = numberPages * 2; i>= 1; --i){
				++page;
				if(i % 2 == 1){

					if(page <= n){
						left[i] = page;
					}
					else{
						left[i] = -1;
					}
				}
				else{
					if(page <= n){
						right[i] = page;
					}
					else{
						right[i] = -1;
					}
				}
			}
			int nPages = 0;
			for(int i = 1; i <= numberPages * 2; ++i){
				if(i % 2 == 1){
					nPages++;
					printf("Sheet %d, front: ", nPages);
					if(left[i]> 0){
						printf("%d", left[i]);	
					}
					else{
						printf("Blank");
					}
					printf(", ");
					if(right[i]> 0){
						printf("%d", right[i]);	
					}
					else{
						printf("Blank");
					}
					printf("\n");
				}
				else{
					printf("Sheet %d, back : ", nPages);
					if(left[i]> 0){
						printf("%d", left[i]);	
					}
					else{
						printf("Blank");
					}
					printf(", ");
					if(right[i]> 0){
						printf("%d", right[i]);	
					}
					else{
						printf("Blank");
					}
					printf("\n");
				}
			}
		}

	}
}