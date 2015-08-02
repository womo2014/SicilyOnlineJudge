//1006. Êý´®×ª»»£¨¼ò»¯£© 
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>

using namespace std;

int main()
{
	double a, b;
	char e;
	
	while ( cin >> a )
	{
		if ( getchar() == 'e' )
		{
			cin >> b;
			a = a*pow(10, b);
		}
		
		cout << fixed << setprecision(10);
		cout << a << endl;
	}
	
	return 0;
} 
