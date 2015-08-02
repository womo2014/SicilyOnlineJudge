#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int f(int x)
{
	int cnt[7] = {0,},factor[7] = {0,};
	int n = x;
	int cnt1 = 0;
	for (int i = 2; i <= n; i++)
	{
		if ( n % i == 0 && i != x)
		{
			factor[++cnt1] = i;
			while ( n % i == 0 )
			{
				cnt[cnt1]++;
				n /= i;
			}
		}
	}
	
	int fx = 0;
	for ( int i = 1; i <= cnt1; i++ )
	{
		fx += cnt[i]*f(x/factor[i]);
	}
	return fx + cnt1;
}
int main()
{
	int x;
	cin >> x;
	cout << f(x) << endl;
	return 0;
}
