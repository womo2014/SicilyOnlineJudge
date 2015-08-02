#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int n;
	int num[1001];
	cin >> n;
	int m = 0;
	for ( int i = 0; i < n; i++ )
	{
		cin >> num[i];
		for ( int j = 0; j < i; j++ )
			if ( num[i] - num[j] > m ) m = num[i]-num[j];
	}
	cout << m << endl;
	return 0;
}

