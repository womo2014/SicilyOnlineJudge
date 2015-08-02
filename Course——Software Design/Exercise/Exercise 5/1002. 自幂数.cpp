//1002. ×ÔÃÝÊý
#include <iostream>
#include <cmath>
 
using namespace std;

int main()
{
	int n;
	cin >> n;
	int i;
	for ( i = pow(10,n-1); i < pow(10,n); i++ )
	{
		int sum = 0;
		int j;
		int copy_i = i;
		for ( j = 0; j < n; j++ )
		{
			sum += pow(i%10, n);
			i /= 10;
		}
		if ( sum == copy_i )
		{
			cout << i << endl;
		}
	}
	return 0;
}
