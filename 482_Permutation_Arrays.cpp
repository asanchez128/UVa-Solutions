#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int N;
	string line;
	
	getline(cin, line);
	sscanf(line.c_str(), "%d", &N);
	for(int i = 0; i < N; ++i){
		if(i > 0){
			printf("\n");
		}
		getline(cin, line);
		getline(cin, line);
		stringstream ss(line);
		vector<int> integers;
		int integer;
		while(ss >> integer){
			integer--;
			integers.push_back(integer);
		}
		getline(cin, line);
		stringstream ss2(line);
		string d;
		vector<string> doubles;
		while(ss2 >> d){
			doubles.push_back(d);
		}
		vector<string> result(doubles.size(), "");
		for(int j = 0; j < doubles.size(); ++j){
			result[integers[j]] = doubles[j];
		}
		for(int j = 0; j < result.size(); ++j){
			cout << result[j] << endl;
		}
	}
	return 0;
}