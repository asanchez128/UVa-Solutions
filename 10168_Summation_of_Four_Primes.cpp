#include <cstdio>
#include <bitset>
#include <vector>
using namespace std;
bitset<10000010> bs;
int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int N;
	vector<int> primes;
	bs.set();
	for(long long i = 2; i <= 10000000; ++i){
		if(bs[i] == true){
			primes.push_back(i);
			for(long long j = i * i; j <= 10000000; j+=i){
				bs[j]= false;
			}
		}
	}
	while(scanf("%d", &N) == 1){
		if(N < 8){
			printf("Impossible.\n");
		}
		else{
			if(N & 1){
				printf("2 3");
				N-=5;
			}
			else{
				printf("2 2");
				N-=4;
			}
			for(size_t i = 0; i < primes.size(); ++i){
				int rest = N - primes[i];
				if(bs[rest] == true){
					printf(" %d %d\n", rest, primes[i]);
					break;
				}
			}
			
		} 
	}
	return 0;
}