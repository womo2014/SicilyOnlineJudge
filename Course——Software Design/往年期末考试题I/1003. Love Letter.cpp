#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int k, n;
	cin >> k >> n;
	string a, b;
	int s[16] = {0};
	cin >> a >> b;
	for ( int i = 0; i < a.size()-1; i++ )
		if ( a[i] == 'A' && a[i+1] == 'C')s[1]++;
	
	for ( int i = 0; i < b.size()-1; i++ )
		if ( b[i] == 'A' && b[i+1] == 'C' )s[2]++;
	
	string x, y;
	x.push_back(a[0]);
	x.push_back('a');
	x.push_back(a[a.size()-1]);
	y.push_back(b[0]);
	y.push_back('a');
	y.push_back(b[b.size()-1]);
	string t;   
	for ( int i = 3; i <= k; i++ )
	{	
		s[i] = s[i-1]+s[i-2];
		t = x+y;
		x = y;
		y = t;
	}
	int cnt = 0;
	for ( int i = 0; i < t.size()-1; i++ )
		if ( t[i] == 'A' && t[i+1] == 'C')cnt++;
	if ( n == s[k]+cnt ) cout << "Accepted" << endl;
	else cout << "Forever alone" << endl;
	return 0;
}