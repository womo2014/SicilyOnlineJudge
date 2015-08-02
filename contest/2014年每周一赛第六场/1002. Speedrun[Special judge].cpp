#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int x;
	while ( cin >> x && x != 0 )
	{
		double minute = 0;
		double p[x];
		int i;
		for ( i = 0; i < x; i++ )
		{
			cin >> p[i];
		}
		for ( i = 0; i < x; i++ )
		{
			if ( i != 0 && p[i] != 1 )
			{
				minute++;
			}
			minute += 1/p[i];
		}
		cout << fixed << setprecision(10);
		cout << minute << endl;
	}
	1.4285714285
	return 0;
}
