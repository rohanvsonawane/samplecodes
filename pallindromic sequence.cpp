#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007



int main() {

	set<string> st;
	freopen ("in.txt","r",stdin);
	freopen ("out.txt","w",stdout);
	
	int q;
	cin >> q;
	for(int m = 0; m < q; m++) {
		int l, n, k;
		cin >> l;
		cin >> n;
		cin >> k;
		int num = 97;
		for(int i = 0; i < n; i++) {
			string s = "";
			s += char(num);
			num++;
			
			st.insert(s);
		}
		for(int i = 0; i < n; i++) {
			string s = "";
			s += char(num);
			s += char(num);
			num++;
			
			st.insert(s);
		}
		for(int i = 0; i < n; i++) {
			if(st.size() > k)
				break;

		}
	}
	return 0;
}