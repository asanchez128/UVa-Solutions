#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;

struct die{
	int top, north, west, east, south, bottom;
};

void turn_north(die &a){
	die temp;
	temp.north = a.top;
	temp.bottom =a.north;
	temp.top = a.south;
	temp.south = a.bottom;
	temp.east = a.east;
	temp.west = a.west;
	
	a = temp;
}

void turn_south(die &a){
	die temp;
	temp.north = a.bottom;
	temp.bottom =a.south;
	temp.top = a.north;
	temp.south = a.top;
	temp.east = a.east;
	temp.west = a.west;
	
	a = temp;
}

void turn_east(die &a){
	die temp;
	temp.east = a.top;
	temp.top = a.west;
	temp.bottom = a.east;
	temp.west = a.bottom;
	temp.north = a.north;
	temp.south = a.south;
	a = temp;
}

void turn_west(die &a){
	die temp;
	temp.east = a.bottom;
	temp.top = a.east;
	temp.bottom = a.west;
	temp.west = a.top;
	temp.north = a.north;
	temp.south = a.south;
	a = temp;
}

void setup(die &a){
	a.east = 4;
	a.top = 1;
	a.bottom = 6;
	a.west = 3;
	a.north = 2;
	a.south = 5;
	
}

char instruction[30];
int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int N;
	while(scanf("%d\n", &N) == 1 && (N > 0)){
		die b;
		setup(b);
		for(int i = 0; i < N; ++i){
			fgets(instruction, 30, stdin);
			
			unsigned int length = strlen(instruction);
			
			instruction[length-1] = '\0';
			length--;
			for(unsigned int i = 0; i < length; ++i){
				instruction[i] = tolower(instruction[i]);
			}
			
			if(strcmp(instruction, "north") == 0){
					turn_north(b);
			}
			else if(strcmp(instruction, "south") == 0){
				turn_south(b);
			}
			else if(strcmp(instruction, "east") == 0){
				turn_east(b);
			}
			else{
				turn_west(b);
			}							
		}
		printf("%d\n", b.top);
	}
	return 0;
}