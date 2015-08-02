#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <cstring>
using namespace std;

int main()
{
	int n, m, x;
	int num[1001];
	
	cin >> n >> m;
	for ( int i = 1; i <= n; i++)
		cin >> num[i];
	
	while ( m-- )
	{
		cin >> x;
		cout << num[x] << endl;
	}
	return 0;
}
