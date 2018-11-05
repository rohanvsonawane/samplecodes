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
	vector<int> mat(w+1, INT_MAX);
	
	mat[0] = 0;
	for(int i = 1; i <= w; i++) {
		for(int j = 0; j < n; j++) {
			if(val[j] <= i) {
				int temp = mat[i - val[j]];
				if(temp != INT_MAX && temp + 1 < mat[i])
					mat[i] = temp+1;
			}
		}
	}
	cout << mat[w] << endl;
	return 0;
}