#include <iostream>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

int v[100001];

int main() {
    ios::sync_with_stdio(false);
	int n, d;
    while ( cin >> n && n ) {   	
    	cin >> d;
    	for ( int i = 0; i < n; i++ ) {
    		cin >> v[i];
    	}
		for ( int i = 0; i < n-1; i++ )
			if ( v[i+1]-v[i] > d ) 
				v[i+1] = v[i] + d;
		for ( int i = n-1; i > 0; i-- )
			if ( v[i-1]-v[i] > d ) 
				v[i-1] = v[i] + d;
    	
        long long sum = 0;
    	for ( int i = 0; i < n; i++ )
    		sum += v[i];
    	cout << sum << endl;
    }
    return 0;
} 