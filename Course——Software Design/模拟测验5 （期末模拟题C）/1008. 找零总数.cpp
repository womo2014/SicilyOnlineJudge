#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int x[1000][7];
int re[7] = {500,200,100,50,10,5,1};
int dp( int num, int k )
{
	if ( num == 0 || k == 6 ) return 1;
	if ( x[num][k] != 0 ) return x[num][k];
	int &ret = x[num][k] = 0;
	for ( int j = 0; j <= num/re[k]; j++ )
			ret += dp(num-j*re[k],k+1);
	return ret;
}

int main()
{
	double t;
	while ( cin >> t )
	{
		int a = t*10;
		cout << dp(a,0) << endl;
	}
	return 0;
}