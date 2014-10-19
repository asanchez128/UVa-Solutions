#include<string>
#include <iostream>
#include <cstdio>
#include <algorithm>
#define debug false
using namespace std;

string get_rid_of_left_zeroes(string s){
	reverse(s.begin(), s.end());
	int indice = s.size() - 1;
	while (indice >= 0 && s[indice] == '0'){
		s.pop_back();
	}
	if (s.size() > 1)
	reverse(s.begin(), s.end());
	return s;
}

int sum_digits(int n){
	int sum = 0;
	while (n){
		sum += (n % 10);
		n /= 10;
	}
	return sum;
}

void isMultipleOfNine(int number, int level){
	if (number < 10){
		if (number == 9){
			printf(" is a multiple of 9 and has 9-degree %d.\n", level);
		}
		else{
			printf(" is not a multiple of 9.\n");
		}
	}
	else{
		int sum = sum_digits(number);
		isMultipleOfNine(sum, level + 1);
	}
}



int main(){
	if (debug){
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	}
	string line;
	getline(cin, line);

	line = get_rid_of_left_zeroes(line);
	
	while (!(line == "0" || line.size() == 0)){
		int sum = 0;
		cout << line;
		for (auto l : line){
			sum += l - '0';
		}
		//if (debug){
		//	//printf("Sum %d", sum);
		//}
		isMultipleOfNine(sum, 1);
		getline(cin, line);
		line = get_rid_of_left_zeroes(line);

	}
	return 0;
}
