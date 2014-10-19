// Author: sanmar1
// Status: accepted
#include <regex>
#include <cstdio>
#include <string>
#include <iostream>
#define debug false

using namespace std;

int main(){
	if (debug){
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	}
	string line;
	int N;
	scanf("%d\n", &N);
	regex reg1(R"((one)|(.ne)|(o.e)|(on.))");
	regex reg2(R"((two)|(.wo)|(t.o)|(tw.))");
	regex reg3(R"((three)|(.hree)|(t.ree)|(th.ee)|(thr.e)|(thre.))");
	while (N--){
		getline(cin, line);
		
		smatch match;
		if (regex_match(line, match, reg1)){
			printf("1\n");
		}
		else if(regex_match(line, match, reg2)){
			printf("2\n");
		}
		else{
			printf("3\n");
		}
	}

	return 0;
}
