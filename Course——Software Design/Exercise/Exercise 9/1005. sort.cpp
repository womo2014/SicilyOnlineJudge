#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int num[205];
	for ( int i = 0; i < n; i++ )
	{
		cin >> num[i];
	}
	
	sort(num, num+n);
	for ( int i = 0; i < n; i++ )
		cout << num[i] << endl;
	return 0;
}
