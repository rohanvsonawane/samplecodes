#include<bits/stdc++.h>
using namespace std;

int main() {

	unordered_multiset<int> st;

	st.insert(5);
	st.insert(5);
	unordered_multiset<int>::iterator it = st.begin();
	while(it != st.end()) {
		cout << *it << endl;
		it++;
	}	

	return 0;
}