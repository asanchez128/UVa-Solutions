#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <bitset>
#define debug false
using namespace std;

vector <vector<int>> adjList;
bitset<30> vis;
void dfs(int u){
	vis[u] = true;
	for (auto v : adjList[u]){
		if (!vis[v]){
			dfs(v);
		}
	}
}
int main(){
	if (debug){
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	}

	int N, size, a, b, scc = 0;
	//scanf("%d\", &N);
	string line;
	getline(cin, line);
	sscanf(line.c_str(), "%d", &N);
	getline(cin, line);
	while (N--){
		adjList.clear();
		getline(cin, line);
		vis.reset();
		scc = 0;
		size = line[0] - 'A' + 1;
		adjList.assign(size + 1, vector<int>());
		getline(cin, line);
		while (!(line.empty())){
			a = line[0] - 'A' + 1;
			b = line[1] - 'A' + 1;
			adjList[a].push_back(b);
			adjList[b].push_back(a);
			getline(cin, line);
		}
		for (int i = 1; i <= size; ++i){
			if (vis[i] == false){
				++scc;
				dfs(i);
			}
		}
		printf("%d\n", scc);
		if (N){
			printf("\n");
		}
		
	}
	return 0;
}