#include<bits/stdc++.h>
using namespace std;
#include MAX_SIZE 256

void getans() {
	string s;
	cin >> s;							abababcdefababcdab
	int arr[MAX_SIZE] = {-1};
	int start = 0;
	int end = 0;
	int finans = 0;
	for(int i = 0; i < s.length(); i++) {
		if(arr[s[i]] == -1) {
			arr[s[i]] = i;
			end++;
		}
		else if(arr[s[i]] != -1) {
			if(end - start > finans)
				finans = end - start;
			start = arr[s[i]] + 1;
			arr[s[i]] = i;
		}
	}
	if(end - start > finans)
		finans = end - start;
	cout << finans << endl;
}

int main() {
	
	int q;
	cin >> q;
	for(int i = 0; i < q; i++)
		getans();
	return 0;
}