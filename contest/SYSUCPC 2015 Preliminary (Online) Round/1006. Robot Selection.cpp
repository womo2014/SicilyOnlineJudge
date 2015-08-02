#include <iostream>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

int num[1002];
int n;
int dp(int dir)
{
	if ( dir > n+1 ) return 0;
	int a = dp(dir+2) + num[dir];
	int b = dp(dir+3) + num[dir];
	if ( a < b ) return b;
	else return a;
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    num[0] = 0;
    while ( t-- )
    { 	
    	cin >> n;
    	for ( int i = 2; i <= n+1; i++ )
    		cin >> num[i];
    	cout << dp(0) << endl;
    }
    
    return 0;
} 