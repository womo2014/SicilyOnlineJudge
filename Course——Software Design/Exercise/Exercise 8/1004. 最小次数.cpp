#include <iostream>

using namespace std;

int main()
{
	int n;
	while ( cin >> n )
	{
		int cnt = 0; 
		while ( n != 1 )
		{
			if ( n == 3 )
				n--;
			else if ( n % 2 == 1 )
			{
				if ( n % 4 == 3 )
					n++;
				else n--;
			}
			else {
				n /= 2;
			}	
			cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
} 
