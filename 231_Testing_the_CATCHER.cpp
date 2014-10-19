#include <cstdio>
#include <vector>
#include <algorithm>

#define debug true

using namespace std;
int main(){
	if (debug){
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	}

	vector<int> v;

	int n;
	int counter = 0;
	scanf("%d", &n);
	while (n >= 0){
		if (counter > 0){
			printf("\n");
		}

		v.clear();
		printf("Test #%d:\n", ++counter);
		while (n >= 0){
			v.push_back(n);
			scanf("%d", &n);
		}
		
		vector<int>lis;
		lis.assign(v.size(), 1);
		for (int i = 1; i < v.size(); ++i){
			for (int j = 0; j < i; ++j){
				if (v[i] <= v[j] && i > j){
					lis[i] = max(lis[i], lis[j] + 1);
				}
			}
		}
		int answer = 0;
		for (auto a : lis){
			answer = max(a, answer);
		}
		printf("  maximum possible interceptions: %d\n", answer);
		scanf("%d", &n);
	}

	return 0;
}