#include <cstdio>
#include <bitset>
#include <ctime>
#include <cstring>
using namespace std;
//bitset<20000010> bs;
bool used[20000010];
int twin_prime[100000 + 10];
int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	memset(used, true, sizeof(used));
	//clock_t t1, t2;
	//t1 = clock();
	for (int i = 2; i * i <= 20000001; ++i){
		if (used[i] == true){
			for (int j = i*i; j <= 20000001; j+=i){
				used[j] = false;
			}
		}
	}

	int counter = 1;
	for (int i = 5; i <= 20000000; i+=2){
		if (used[i] && used[i - 2]){
			twin_prime[counter++] = i-2;
		}
	}
	//t2 = clock();
	/*float diff((float)t2 - (float)t1);
	printf("%f\n", diff/CLOCKS_PER_SEC);;
*/
	int N;
	while (scanf("%d", &N) == 1){
		printf("(%d, %d)\n", twin_prime[N], twin_prime[N] + 2);
	}
	return 0;
}