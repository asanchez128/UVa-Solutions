#include <cstdio>
#include <cstring>

int main() {
	char B[30];
	int vis[30], cnt[30], T;
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	scanf("%d", &T);
	while (T--){
		scanf("%s", B);
		memset(vis, 0, sizeof(vis));
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < 26; ++i){
			if (vis[i] == 0){
				int j = i, n = 0;
				do{
					vis[j] = 1;
					j = B[j] - 'A';
					n++;
				} while (j != i);
				cnt[n]++;
			}
		}
		int ok = 1;
		for (int i = 2; i <= 26; i+=2){
			if ((cnt[i] % 2) == 1){
				ok = 0;
			}
		}
		if (ok){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}

	return 0;
}