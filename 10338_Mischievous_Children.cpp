// Status: Accepted
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#define debug false
using namespace std;

void frequency(string s, vector<int>&v){
	for (int i = 0; i < s.size(); ++i){
		v[s[i]-'A']++;
	}
}

long long factorial[30];

int main(){
	if (debug){
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	}
	int N;
	cin >> N;
	string line;
	vector<int>v;
	factorial[1] = 1ll;
	for (int i = 2; i <= 20; ++i){
		factorial[i] = (factorial[i - 1] * i);
	}
	int counter = 0;
	while (N--){
		cin >> line;
		v.clear();
		v.assign(26, 0);
		frequency(line, v);
		long long denominator=1ll;
		for (int i = 0; i < 26; ++i){
			if (v[i]>1){
				denominator *= (factorial[v[i]]);
			}
		}
		printf("Data set %d: %lld\n", ++counter, factorial[line.size()]/denominator);
	}

}