#include<cstdio>

using namespace std;

int main(){
	int t;

	int n, p, k;
	//freopen("Text.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
		scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		scanf("%d%d%d", &n, &p, &k);
		int result = (p + k) % n;
		if(result == 0) result = n;
		printf("Case %d: %d\n", i + 1, result);
	}
}