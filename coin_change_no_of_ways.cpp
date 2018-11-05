// Coin change problem

#include<bits/stdc++.h>
using namespace std;
int max(int a, int b) { return (a > b)? a : b; }
int main() {
	
	int n;
	cin >> n;
	vector<int> val(n, 0);
	for(int i = 0; i < n; i++)
		cin >> val[i];
	int w;
	cin >> w;
	vector<vector<int> > mat(n+1, vector<int> (w+1, 0));
	for(int i = 1; i <= n; i++)
		mat[i][0] = 1;
	for(int j = 0; j <= w; j++)
		mat[0][j] = 0;
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= w; j++) {
			if(j < val[i-1]) 
				mat[i][j] = mat[i-1][j];
			else {
				mat[i][j] = max(mat[i-1][j], mat[i][j - val[i-1]]+1);
			}
			
		}
	}
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= w; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	cout << mat[n][w] << endl;
	return 0;
}