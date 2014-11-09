#include <cstring>
#include <sstream>
#include <string>
#include <iostream>
#include <cstdio>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

struct contestant{
		int _contestant, problem, time;
		char L;
		contestant(int _c, int _p, int _t, char _L){
			_contestant = _c, problem = _p, time = _t, L = _L;
		}
};

struct score{
	int id, total_solve, time;
	score(int _i, int _s, int _t){
		id = _i, total_solve = _s, time = _t;
	}
};

int grid[110][15];
int solved[110][15];
int total_solve[110];
int _time[110];
int participating[110];
int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int N;
	string line;
	int _con, problem, time;
	char L;
	getline(cin, line);
	sscanf(line.c_str() ,"%d", &N);
	getline(cin, line);
	for(int i = 0; i < N; ++i){
		if(i > 0) printf("\n");
		memset(solved, -1, sizeof(solved));
		memset(_time, 0, sizeof(_time));
		memset(grid, 0, sizeof(grid));
		memset(total_solve, 0, sizeof(total_solve));
		memset(participating, 0, sizeof(participating));
		
		while(getline(cin, line) && !line.empty()){
			stringstream ss(line);
			ss >> _con >> problem >> time >> L;
			L = toupper(L);
			participating[_con] = 1;
			if(L == 'C'){
				if(solved[_con][problem] < 0){
					solved[_con][problem] = 1;
					_time[_con] += (time + 20 * grid[_con][problem]);
					total_solve[_con]++;
				}
			}
			else if(L == 'I'){
				if(solved[_con][problem] < 0){
					grid[_con][problem]++;
				}
			}
		}
		vector<score> myscores;
		for(int i = 1; i <= 100; ++i){
			if(participating[i]){
				score sc(i, total_solve[i], _time[i]);
				myscores.push_back(sc);
			}
		}
		sort(myscores.begin(), myscores.end(), [](const score &a, const score &b){
			if(a.total_solve != b.total_solve){
				return (a.total_solve > b.total_solve);
			}
			else if(a.time != b.time){
				return (a.time < b.time);
			}
			else{
				return (a.id < b.id);
			}
		});
		for(auto item : myscores){
			printf("%d %d %d\n", item.id, item.total_solve, item.time);
		}
		
		
		myscores.clear();
	}
	return 0;
	
}