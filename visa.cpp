#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int arr[n+1];
		for(int i = 1; i <= n; i++) {
			int curr; 
			cin >> curr;
			arr[curr] = i;
		}
		vector<bool> check(8, false);
		check[0] = true;
		int i;
		for(i = 1; i <= n; i++) {
			bool ans = true;
			if(arr[i] <= 7) {
				check[arr[i]] = true;
			}
			for(int j = 1; j <= 7; j++) {
				ans &= check[j];
			}
			if(ans) {
				break;
			}
		}
		cout << i << '\n';
	}
}