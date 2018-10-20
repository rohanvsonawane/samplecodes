#include<bits/stdc++.h>
using namespace std;

int main() {
	
	int v[7] = {0};
	for(int i = 0; i < 3; i++) {
		int m, n, p;
		cin >> m;
		cin >> n;
		cin >> p;
		v[m] += p;
		if(n < 6)
			v[n+1] -= p; 
	}
	cout << v[0] << " ";
	for(int i = 1; i < 7; i++) {
		v[i] += v[i-1];
		cout << v[i] << " ";
	}

	return 0;
}