#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int arr[N][N];
bool vis[N][N];
int n, m;
vector<pair<int,int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int cnt = 0;
bool isValid(int x, int y) {
	if(x < 0 or y < 0 or x >= n or y >= m)
		return false;
	if(vis[x][y] == 1)
		return false;
	return true;
}
void dfs(int x, int y) {
	cnt++;
	vis[x][y] = 1;
	for(auto i : moves) {
		if(isValid(x + i.first, y + i.second)) {
			if(arr[x][y] == arr[x + i.first][y + i.second]) {
				dfs(x + i.first, y + i.second);
			}
		}
	} 
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> arr[i][j];
			vis[i][j] = false;
		}
	}
	int max_bnk = 0, min_str = 1e9+4;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(vis[i][j] == 0) {
				dfs(i, j);
				if(cnt >= max_bnk) {
					if(cnt == max_bnk && arr[i][j] < min_str) {
						max_bnk = cnt;
						min_str = arr[i][j];
					}
					else if(cnt > max_bnk) {
						max_bnk = cnt;
						min_str = arr[i][j];
					}
				}
				cnt = 0;
			}
		}
	}
	cout << min_str << " " << max_bnk;
	
	return 0;
}