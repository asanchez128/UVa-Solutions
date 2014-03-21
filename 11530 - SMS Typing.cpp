#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
char line[200];
int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int t;
	gets(line);
	sscanf(line, "%d\n", &t);
	
	int values[] = {0, 1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
	for(int i = 0; i < t; ++i){
		gets(line);
		int size = strlen(line);
		int sum = 0;
		for(int j = 0; j < size; ++j){
			char c = line[j];
			if(isspace(c)){
				sum += 1;
			}
			else{
				int index = c - 'a' + 1;
				sum += values[index];
			}
		}
		printf("Case #%d: %d\n", i+1, sum);

	}
}