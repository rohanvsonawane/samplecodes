#include<bits/stdc++.h>
using namespace std;

int main() {
	
	int k;
	cin >> k;
	int v[5] = {5, 2, 4, 1, 3};
	sort(v, v+5);
	float avg[5];
	avg[0] = v[0];
	cout << avg[0] << " ";
	for(int i = 1; i < 5; i++) {
		avg[i] = (avg[i - 1]*(i) + v[i])/(float)(i+1);
		cout << avg[i] << " ";
	}
	cout << endl;
	int ans;
	for(int i = 0; i < 5; i++) {
		if(avg[i] < k)
			ans = i+1;
	}
	cout << ans << endl;
	return 0;
}