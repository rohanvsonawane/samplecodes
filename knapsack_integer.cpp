// 0/1 knapsack problem

#include<bits/stdc++.h>
using namespace std;
int max(int a, int b) { return (a > b)? a : b; }
int main() {
	
	int n;
	cin >> n;
	vector<int> val(n, 0);
	vector<int> wt(n, 0);
	for(int i = 0; i < n; i++)
		cin >> val[i];
	for(int i = 0; i < n; i++)
		cin >> wt[i];
	int w;
	cin >> w;
	for(int i = 0; i < n; i++)
		cout << val[i] << " ";
	cout << endl;
	for(int i = 0; i < n; i++)
		cout << wt[i] << " ";
	cout << endl;
	vector<vector<int> > mat(n+1, vector<int> (w+1, 0));
	// for(int i = 0; i <= n; i++) {
	// 	for(int j = 0; j <= w; j++) {
	// 		cout << mat[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= w; j++) {
			if(wt[i-1] <= j) {
				mat[i][j] = max(mat[i-1][j], val[i-1]+mat[i-1][j-wt[i-1]]);
			}
			else {
				mat[i][j] = mat[i-1][j];
			}
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << mat[n][w];
	return 0;
}