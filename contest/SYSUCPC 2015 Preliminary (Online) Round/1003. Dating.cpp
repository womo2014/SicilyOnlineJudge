#include <iostream>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
#include <set>
using namespace std;

int d[101][101];

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while ( t-- ) {
    	int n, m;
    	cin >> n >> m;
    	memset(d, 10001, sizeof(d));
    	int u, v;
    	while ( m-- ) {
    		cin >> u >> v;
    		d[u][v] = 0;
    		if ( d[v][u] > 1 ) d[v][u] = 1;
    	}
    	for ( int k = 1; k <= n; k++ )
    		for ( int i = 1; i <= n; i++ )
    			for ( int j = 1; j <= n; j++)
    				d[i][j] = min(d[i][j], d[i][k]+d[k][j] );
    	if ( d[1][n] > 10000 ) cout << -1 << endl;
    	else cout << d[1][n] << endl;

    }
    return 0;
} 