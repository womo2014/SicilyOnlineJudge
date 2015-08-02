#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

int factor[10];
int main()
{
	string a;
	cin >> a;
	for ( int i = a.size()-1; i >= 0; i-- )
	{
		if ( a[i] >= '0' && a[i] <= '9' )
			a[i] = '*';
		else if ( a[i] >= 'a' && a[i] <= 'z' )
			a[i] += 'A' - 'a';
		else if ( a[i] >= 'A' && a[i] <= 'Z' )
			a[i] += 'a' - 'A';
		cout << a[i];
	}
	cout << endl;
	
	return 0;
}

