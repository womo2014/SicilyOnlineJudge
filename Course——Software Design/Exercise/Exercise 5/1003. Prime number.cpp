//1003. Prime number
#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	if ( n == 1)
	{
		 cout << "No" << endl;
	}
	else 
	{
		int i;
		for ( i = 2; i*i <= n; i++ )
		{
			if ( n % i == 0 )
			{
				cout << "No" << endl;
				return 0;
			}
		}
		cout << "Yes" << endl;
	}
	return 0;
}
