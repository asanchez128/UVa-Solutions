#include <cstdio>
#define debug false
using namespace std;

long long state[55];
int main(){
	if (debug){
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	}
	state[1] = 2;
	state[2] = 3;
	for (int i = 3; i <= 51; ++i){
		state[i] = state[i - 1] + state[i - 2];
	}
	int N;

	scanf("%d\n", &N);
	int scenario;
	int counter = 0;
	while (N--){
		scanf("%d", &scenario);
		printf("Scenario #%d:\n%lld\n\n", ++counter, state[scenario]);
	}
	return 0;
}
