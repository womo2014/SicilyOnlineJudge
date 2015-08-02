#include <iostream>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    int n, m;
    char fuck[101][101];
    while ( t-- ) {
    	int cnt = 0;
    	cin >> n >> m;
    	for ( int i = 0; i < n; i++ )
    		for ( int j = 0; j < m; j++ )
    			cin >> fuck[i][j];
    	for( int i = 0; i < (n+1)/2; i++ ) {
    		for ( int j = 0; j < (m+1)/2; j++ ) {
    			int t = 0;
    			if ( fuck[i][j] == 'a' ) t++;
    			if ( fuck[n-i-1][j] == 'a' ) t++;
    			if ( fuck[i][m-j-1] == 'a' ) t++;
    			if ( fuck[n-i-1][m-j-1] == 'a' ) t++;
    			if ( t & 1) ++cnt;
    			else if ( t == 2 ) {
    				if( i == n-i-1 || j == m-j-1 ) 
    					++cnt;
    				else cnt += 2;
    			}
    		}
    	}
    	cout << cnt << endl;
    }
    
    return 0;
} 