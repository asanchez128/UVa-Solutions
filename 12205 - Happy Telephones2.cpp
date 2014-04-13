#include<cstdio>
#include<vector>
#include <set>
using namespace std;
typedef pair<long long int, long long int> pii;
typedef pair<pii, pii> piv;
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m;
	while(scanf("%d%d", &n, &m) && (n || m)){
		vector<pii> intervals;
		set<pii> mySet;
		
		long long source, dest, start, dur, end;
		for(int i = 0; i < n; ++i){
			scanf("%lld%lld%lld%lld", &source, &dest, &start, &dur);
			end = start + dur;
			//printf("end:%lld\n", end);

			
				/*if(dest < source){
					long long temp = dest;
					dest = source;
					source = temp;
				}*/
				//piv front(pii(source, dest), pii(start, dur));
				pii front(pii(source, dest));
				//if(mySet.count(front) == 0){
					mySet.insert(front);
					intervals.push_back(pii(start, end));
				//}
				
		}
/*
		for(int i = 0; i < intervals.size(); ++i){
			printf("%lld %lld\n", intervals[i].first, intervals[i].second);
		}*/
		long long pol_start, pol_dur, pol_end;
		vector<pii> pol_ranges;
		for(int j = 0; j < m; ++j){
			scanf("%lld%lld", &pol_start, &pol_dur);
			pol_end = pol_start + pol_dur;
			//printf("end:%lld\n", pol_end);
			pol_ranges.push_back(pii(pol_start, pol_end));
		}
		/*printf("\n\n");
		for(int i = 0; i < pol_ranges.size(); ++i){
			printf("%lld %lld\n", pol_ranges[i].first, pol_ranges[i].second);
		}*/
		for(int k = 0; k < pol_ranges.size(); ++k){
			int sum = 0;
			long long range_first, range_second;
			range_first = pol_ranges[k].first;
			range_second = pol_ranges[k].second;

				for(int i = 0; i < intervals.size(); ++i){
					long long interval_first, interval_second;
					interval_first = intervals[i].first; 
					interval_second = intervals[i].second;
					if(interval_first < range_second && range_first < interval_second){
						++sum;
					}
					

				}
			printf("%d\n", sum);
		}

	}
		
}