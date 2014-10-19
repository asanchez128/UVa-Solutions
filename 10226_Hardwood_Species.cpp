#include <cstdio>
#include <string>
#include <iostream>
#include <map>
#define debug false
using namespace std;

int main(){
	if (debug){
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	}
	int N;
	string line;
	getline(cin, line);
	sscanf(line.c_str(), "%d", &N);
	//getline(cin, line);
	map<string, int> m;
	getline(cin, line);
	while (N--){
		int total = 0;
		m.clear();
		while (getline(cin, line) && !line.empty()){
			m[line]++;
			++total;
		}
		for (auto item : m){
			printf("%s %.4lf\n", item.first.c_str(), ((double)item.second*100.00) / total);
		}
		if (N){
			printf("\n");
		}
	}

	return 0;
}