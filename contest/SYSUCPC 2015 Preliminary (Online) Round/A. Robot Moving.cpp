#include <iostream>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

char maze[200][200];
int dir[255][2];
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    dir['U'][0] = -1;
    dir['D'][0] = 1;
    dir['L'][1] = -1;
    dir['R'][1] = 1;
    while ( t-- ) {
    	int n, m;
    	cin >> n >> m;
    	memset(maze, 'x', sizeof(maze));
    	for ( int i = 1; i <= n; i++ )
    		for ( int j = 1; j <= m; j++ )
    			cin >> maze[i][j];
    	string a;
    	cin >> a;
    	int x = 1, y = 1;
    	for ( int i = 0; i < a.size(); ++i ) {
    		int tx = x + dir[a[i]][0];
    		int ty = y + dir[a[i]][1];
    		if ( maze[tx][ty] == '.' ) {
    			x += dir[a[i]][0];
    			y += dir[a[i]][1];
    		}
    	}
    	cout << x << ' ' << y << endl;
    }
    
    return 0;
} 