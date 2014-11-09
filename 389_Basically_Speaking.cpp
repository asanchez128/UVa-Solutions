#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

map<char, int> letter_to_number;
map<int, char> number_to_letter;

bool is_letter(char c){
	string letters = "ABCDEF";
	for(size_t t = 0; t < letters.size(); ++t){
		if(letters[t] == c)return true;
	}
	return false;
}
void get_rid_leading_zeroes(string& s){
	while(s.size() > 1 && s.front() == '0'){
		s.erase(s.begin());
	}
}

string convert(string s, int base_input, int base_output){
	get_rid_leading_zeroes(s);
	int result = 0;
	int number;
	for(size_t t = 0; t < s.size(); ++t){
		if(is_letter(s[t])){
			number = letter_to_number[s[t]];
		}
		else{
			number = s[t] - '0';
		}
		result = result * base_input + (number); 
	}
	
	string converted;
	char output_char;
	if(result > 0){	
		while(result > 0){
			int temp = result % base_output;
			if(temp > 9){
				output_char = number_to_letter[temp];
			}
			else{
				output_char = temp + '0';
			}
			converted.push_back(output_char);
			result /= base_output;
		}
	}
	else{
		converted.push_back(result + '0');
	}
	reverse(converted.begin(), converted.end());
	return converted;
}

int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	letter_to_number['A'] = 10;
letter_to_number['B'] = 11;
letter_to_number['C'] = 12;
letter_to_number['D'] = 13;
letter_to_number['E'] = 14;
letter_to_number['F'] = 15;

number_to_letter[10] = 'A';
number_to_letter[11] = 'B';
number_to_letter[12] = 'C';
number_to_letter[13] = 'D';
number_to_letter[14] = 'E';
number_to_letter[15] = 'F';
	string line;
	int base_input;
	int base_convert_to;
	while(cin >> line >> base_input >> base_convert_to){
		for(size_t t = 0; t < line.size(); ++t){
			if(is_letter(line[t]))
			line[t] = toupper(line[t]);
		}
		string output = convert(line, base_input, base_convert_to);
		if(output.size() > 7){
			printf("  ERROR\n");
		}
		else{
			printf("%7s\n", output.c_str());
		}
	}
	
	return 0;
}