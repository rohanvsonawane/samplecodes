#include<bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;
	vector<int> arr(n, 0);
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int sum;
	cin >> sum;
	vector<vector<int> > dp(n, vector<int>(sum+1, 0));
	for(int i = 0; i < n; i++) {
		dp[i][0] = 1;
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 1; j <= sum; j++) {
			if(i == 0) {
				if(arr[i] == j)
					dp[i][j] = 1;
			}
			else {
				if(arr[i] > j) {
					dp[i][j] = dp[i - 1][j];
				}
				else {
					dp[i][j] = dp[i-1][j-arr[i]];
				}
			}
		}
		
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= sum; j++)
			cout << dp[i][j] << " ";
		cout << endl;
	}
	cout << "\n" << dp[n-1][sum] << endl;;
	return 0;
}