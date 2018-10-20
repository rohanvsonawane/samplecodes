#include<bits/stdc++.h>
using namespace std;

void getans() {
  int n;
  vector<string> sv;
  int maxl = INT_MAX;
  for(int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if(s.length() < maxl)
      maxl = s.length();
    sv.push_back(s);
  }
  int result = 0;
  int flag = 0;
  for(int i = 0; i < maxl; i++) {
    flag = 0;
    for(int j = 1; j < n; j++) {
      if(sv[j][i] != sv[j-1][i]) {
        flag = 1;
        break;
      }

    }
    cout << flag << endl;
    if(flag == 1) {
      if(result == 0)
        cout << -1 << endl;
      else {
        for(int m = 0; m < result; m++)
          cout << sv[0][m];
        cout << endl;
      }
      break;
    }
    else
      result++;
  }

}

int main() {
  int q;
  cin >> q;
  for(int i = 0; i < q; i++)
    getans();
  return 0;
}
