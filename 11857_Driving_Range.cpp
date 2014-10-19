#include <cstdio>
#include <vector>
#include <algorithm>
#define debug false

using namespace std;

typedef pair<int, int> ii;

class UnionFind {    
private:
	vector<int> p, rank, setSize;                       // remember: vi is vector<int>
	int numSets;
public:
	UnionFind(int N) {
		setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
		p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i;
	}
	int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
	bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
	void unionSet(int i, int j) {
		if (!isSameSet(i, j)) {
			numSets--;
			int x = findSet(i), y = findSet(j);
			// rank is used to keep the tree short
			if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
			else                   {
				p[x] = y; setSize[y] += setSize[x];
				if (rank[x] == rank[y]) rank[y]++;
			}
		}
	}
	int numDisjointSets() { return numSets; }
	int sizeOfSet(int i) { return setSize[findSet(i)]; }
};
int main(){
	if (debug){
		freopen("in.txt","r", stdin);
		freopen("out.txt", "w", stdout);
	}

	int N, M, a, b, c;
	scanf("%d%d", &N, &M);

	while ((N || M)){
		vector< pair<int, ii> > edgeList;

		for (int i = 0; i < M; ++i){
			scanf("%d %d %d\n", &a, &b, &c);
			edgeList.push_back(make_pair(c, make_pair(a, b)));
			edgeList.push_back(make_pair(c, make_pair(b, a)));
		}

		sort(edgeList.begin(), edgeList.end());
		UnionFind UF(N);
		int max_length = 0;
		int mstEdge = 0;
		for (int i = 0; i < edgeList.size() && mstEdge < (N - 1); ++i){
			auto front = edgeList[i];
			if (!UF.isSameSet(front.second.first, front.second.second)){
				UF.unionSet(front.second.first, front.second.second);
				max_length = max(max_length, front.first);
				++mstEdge;
			}
		}
		if (mstEdge == N - 1){
			printf("%d\n", max_length);
		}
		else{
			printf("IMPOSSIBLE\n");
		}
		scanf("%d%d", &N, &M);
	}
	

	return 0;
}