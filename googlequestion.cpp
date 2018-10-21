#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int freq[26];
long dp[26];

long power(int num, int index) {
	long ans = 1;
	int ct = 0;
	while(ct < index) {
		ans *= num % MOD;
		ct++;
	}
	return ans;
}

long gethash(string sub) {
	//cout << "hi1" << endl;
	long ans = 0;
	for(int i = 0; i < 26; i++) {
		freq[i] = 0;
	}
	for(int i = 0; i < sub.length(); i++) {
		freq[sub[i] - 'A']++;

	}
	
	int j = 0;
	for(int i = 0; i < 26; i++) {
		if(freq[i] != 0) {
			ans = (ans * power(dp[i], freq[i])) % MOD;  
		}
	}
	return ans;
}


int main() {

	dp[0] = 2;
	dp[1] = 3;
	dp[2] = 5;
	int i = 3;
	int num = 6;
	while(i < 26){
		int flag = 0;
		for(int j = 2; j < num/2; j++) {
			if(num % j == 0) {
				flag = 1;
				break;
			}
		}
		if(flag == 0) {
			dp[i] = num;
			i++;
		}
		num++;

	}
	for(int i = 0; i < 26; i++) {
		cout << dp[i] << " ";
	}
	cout << endl;
	unordered_map<long, int> mp;
	//set<string> st;
	freopen ("in.txt","r",stdin);
	freopen ("out.txt","w",stdout);
	
	int q;
	cin >> q;
	for(int m = 0; m < q; m++) {
		int count1 = 0;
		int n;
		cin >> n;
		string s1, s2;
		cin >> s1;
		cin >> s2;

		for(int i = 1; i <= n; i++) {
			for(int j = 0; j < n - i + 1; j++) {
				string sub = s2.substr(j, i);
				//cout << sub << "\n";
				long hash1 = gethash(sub);
				//sort(sub.begin(), sub.end());
				if(mp.find(hash1) == mp.end()) {
					mp[hash1] = 1;
				}
				//st.insert(sub);

			}

			for(int j = 0; j < n - i + 1; j++) {
				string sub = s1.substr(j, i);
				long hash1 = gethash(sub);
				if(mp.find(hash1) != mp.end()) {
					count1++;
				}
				//sort(sub.begin(), sub.end());
				// if(st.find(sub) != st.end())
				// 	count1++;
			}
			mp.clear();
		}

		
		cout << "Case #" << m+1 << ": "<< count1 << "\n";


	}
	
	return 0;
}