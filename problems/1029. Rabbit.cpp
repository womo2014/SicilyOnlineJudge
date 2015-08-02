//1029. Rabbit
#include <iostream>

using namespace std;

int main()
{
	int m;
	int d;
	while (cin >> m >> d && m*d != 0)
	{
		unsigned long long age[11] = {0, };
		age[m] = 1;
		int i;
		unsigned long long ret(0);
		
		while ( d-- )
		{
			unsigned long long x = age[m];
			for ( i = m; i > 1; i-- )
			{
				age[i] = age[i-1];
			}
			age[1] = x;
			age[m] += x;
		}
		
		for ( i = 1; i <= m; i++ )
		{
			ret += age[i];
		}
		cout << age[m] << endl;
	}	
	return 0;
} 
