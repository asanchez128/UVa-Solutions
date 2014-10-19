#include <cstdio>
#include <set>
#define debug false
using namespace std;

int main(){
	if (debug){
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	}
	int N, number, no;
	multiset<int> tickets;
	auto result = 0LL;
	scanf("%d", &N);
	while (N > 0){
		tickets.clear();
		result = 0LL;
		while (N--){
			scanf("%d", &number);
			for (int i = 0; i < number; ++i){
				scanf("%d", &no);
				tickets.insert(no);
				
			}
			result += (*tickets.crbegin() - *tickets.cbegin());
			tickets.erase(tickets.begin());
			tickets.erase(tickets.find(*tickets.rbegin()));
		}

		scanf("%d", &N);
		printf("%lld\n", result);
	}
	
	return 0;
}
