#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
	string a;
	cin >> a;
	for ( int i = 0; i < a.size(); i++ )
	{
		if ( a[i] > 'a' )a[i]--;
		else a[i] = 'z';
		cout << a[i];
	}
	cout << endl;
	
	return 0;
}
