#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <algorithm>
#include <iostream>
using namespace std;
string matrix[150][150];
int main(){
	
	int N; 
	string line;
	while(scanf("%d", &N) == 1){
		size_t max_size = 0U;
		vector<string> input;
		for(int i = 0; i < N; ++i){
			cin >> line;
			max_size = max(max_size, line.size());
			input.push_back(line);
		}
		sort(input.begin(), input.end());
		size_t C = (60 - max_size) / (max_size + 2) + 1;
		size_t R = (N + C - 1)/C;
		for(int i = 0; i < 60; ++i)
		printf("-");
		printf("\n");
		for(size_t i = 0; i < R; ++i){
			for(size_t j = i; j < N; j+=R){
				printf("%-*s", max_size + 2, input[j].c_str());
			}
			printf("\n");
		}
		
	}
		
	
	return 0;
}
