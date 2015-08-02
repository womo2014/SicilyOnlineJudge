#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

bool judge( int num )
{
	int digit[10];
	int cnt = 0;
	while ( num )
	{
		digit[cnt++] = num % 10;
		num /= 10;
	}
	for ( int i = 0; i < cnt/2; i++ )
		if ( digit[i] != digit[cnt-1-i] ) return false;
	return true;
}

void reverse1( int *num)
{
	int temp = *num;
	int t = 0;
	while ( temp )
	{
		t = t*10 + temp%10;
		temp /= 10;
	}
	*num = *num+t;
}

int main()
{
	int n;
	cin >> n;
	int num;
	while ( n-- )
	{
		cin >> num;
		while ( 1 )
		{
			if ( judge(num) )
			{
				cout << num << endl;
				break;
			}
			reverse1( &num );
		}
	}
	return 0;
}




