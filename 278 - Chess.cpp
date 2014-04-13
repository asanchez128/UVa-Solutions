#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int t;
	scanf("%d\n", &t);
	char c;
	int M, N;
	int answer = 0;
	for(int i = 0; i < t; ++i){
		scanf("%c %d %d\n", &c, &M, &N);
		answer = 0;
		if(c == 'r'){
			answer = min(M, N);
		}
		else if(c == 'Q'){
			answer = min(M, N);
		}
		else if(c == 'k'){
			answer = (((M + 1)/2) * ((N + 1)/2)) + (((M)/2) * ((N)/2));
		}
		else if(c == 'K'){
			answer = (((M + 1)/2) * ((N + 1)/2));
		}
		printf("%d\n", answer);
	}
}