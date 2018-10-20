using namespace std;

int minIns( string s, int start, int end, vector <vector <int>> &dp )
{
	if( start >= end )
		return 0;

	if( dp[start][end] != -1 )
		return dp[start][end];

	if( s[start] == s[ end ] )
		return dp[start][end] = minIns( s, start+1, end-1, dp );
	else
		return dp[start][end] = 1+ min( minIns( s, start+1, end, dp ), minIns( s, start, end-1, dp ) );
}


int main()
{
    int t;
    cin >> t;
    while( t-- )
    {
        string s;
    	cin >> s;
    	vector <vector <int>> dp( s.size(), vector <int> (s.size(), -1) );
    	cout << minIns( s, 0, s.size()-1, dp ) << endl;   
    }
}