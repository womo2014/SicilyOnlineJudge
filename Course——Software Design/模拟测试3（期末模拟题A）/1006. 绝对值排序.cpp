#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(int a, int b)
{
	return abs(a) > abs(b);
}

int main()
{
	int n;
	int num[100];
	while ( cin >> n && n )
	{
		for ( int i = 0; i < n; i++ )
			cin >> num[i];
		sort(num,num+n,cmp);
		cout << num[0];
		for ( int i = 1; i < n; i++ )
			cout << ' ' << num[i];
		cout << endl;
	}

	return 0;
}