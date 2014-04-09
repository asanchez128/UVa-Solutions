#include <algorithm>
#include <bitset>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

typedef vector<int> vi;

#define MAX_V 120
#define INF 1000000000

int res[MAX_V][MAX_V], mf, f, s, t;                          // global variables
vi p;
vector<vi> AdjList;

void augment(int v, int minEdge) {     // traverse BFS spanning tree from s to t
	if (v == s) { f = minEdge; return; }  // record minEdge in a global variable f
	else if (p[v] != -1) { augment(p[v], min(minEdge, res[p[v]][v])); // recursive
	res[p[v]][v] -= f; res[v][p[v]] += f; }       // update
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int V, vertex_a, vertex_b, weight, numberConnections, tc = 0;
	while(scanf("%d", &V) == 1 && V > 0){
		scanf("%d %d %d", &s, &t, &numberConnections);
		--s, --t;
		memset(res, 0, sizeof res);
		AdjList.assign(V, vi());
		for (int i = 0; i < numberConnections; i++) {
				scanf("%d %d %d", &vertex_a, &vertex_b, &weight);
				vertex_a--;
				vertex_b--;
				res[vertex_a][vertex_b] += weight;
				res[vertex_b][vertex_a] += weight;
				AdjList[vertex_a].push_back(vertex_b);
				AdjList[vertex_b].push_back(vertex_a);
		}

		mf = 0;
		while (1) {                     // now a true O(VE^2) Edmonds Karp's algorithm
			f = 0;
			bitset<MAX_V> vis; vis[s] = true;            // we change vi dist to bitset!
			queue<int> q; q.push(s);
			p.assign(MAX_V, -1);
			while (!q.empty()) {
				int u = q.front(); q.pop();
				if (u == t) break;
				for (int j = 0; j < (int)AdjList[u].size(); j++) {  // we use AdjList here!
					int v = AdjList[u][j];
					if (res[u][v] > 0 && !vis[v])
						vis[v] = true, q.push(v), p[v] = u;
				}
			}
			augment(t, INF);
			if (f == 0) break;
			mf += f;
		}

		printf("Network %d\nThe bandwidth is %d.\n", ++tc, mf);                              // this is the max flow value
	}
	return 0;
}

