#include <bits/stdc++.h>
using namespace std;
vector <int> dp[102][102];
int A[102][102];
bool obs[102][102];
int main()
{
	int t,n,m,q,x,a,b;
	cin >> t;
	while ( t-- ) {
        cin >> n >> m;
        for ( int i = 0; i < n; i++ ) {
        	for ( int j = 0; j < m; j++ ) obs[i][j] = false, dp[i][j].clear();
        }
        for ( int i = 0; i < n; i++ ) {
        	for ( int j = 0; j < m; j++ ) {
        		string s;
        		stringstream ss;
        		ss.clear();
        		cin >> s;
        		if ( s == "##" ) obs[i][j] = true, A[i][j] = -1;
        		else {
        			ss << s;
        			ss >> A[i][j];
        		}
        	}
        }
        if ( !obs[0][0] ) dp[0][0].push_back(A[0][0]);
        for ( int i = 1; i < n; i++ ) {
        	if ( !obs[i][0] ) {
        		if ( (int)dp[i-1][0].size() > 0 ) dp[i][0].push_back(A[i][0] + dp[i-1][0][0]);
        	}
        }
        for ( int j = 1; j < m; j++ ) {
        	if ( !obs[0][j] ) {
        		if ( (int)dp[0][j-1].size() > 0 ) dp[0][j].push_back(A[0][j] + dp[0][j-1][0]);
        	}
        }
        
        for ( int i = 1; i < n; i++ ) {
        	for ( int j = 1; j < m; j++ ) {
        		if ( !obs[i][j] ) {
        			int sz1 = (int)dp[i-1][j].size();
        			int sz2 = (int)dp[i][j-1].size();
        			int idx1 = 0, idx2 = 0, cnt = 0;
        			while ( (idx1 < sz1 || idx2 < sz2) && cnt != 101 ) {
        				if ( idx2 == sz2 ) {
        					dp[i][j].push_back(A[i][j]+dp[i-1][j][idx1]);
        					idx1++;
        				}
        				else if ( idx1 == sz1 ) {
        					dp[i][j].push_back(A[i][j]+dp[i][j-1][idx2]);
        					idx2++;
        				}
        				else {
        					if ( dp[i-1][j][idx1] > dp[i][j-1][idx2] ) {
        						dp[i][j].push_back(A[i][j]+dp[i][j-1][idx2]);
        						idx2++;
        					}
        					else {
        						dp[i][j].push_back(A[i][j]+dp[i-1][j][idx1]);
        						idx1++;
        					}
        				}
        				cnt++;
        			}
        		}
        	}
        }
        cin >> q;
        while ( q-- ) {
        	cin >> a >> b >> x;
        	if ( obs[a][b] ) {
        		cout << "Obstacle" << endl;
        		continue;
        	}
        	else if ( x > (int)dp[a][b].size() ) {
        		cout << "Not so many paths" << endl;
        		continue;
        	}
        	cout << dp[a][b][x-1] << endl;
         }
	}
	return 0;
}