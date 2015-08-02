#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	long long x, y;
	cin >> x >> y;
	long long max_x = x, min_x = x;
	long long max_y = y, min_y = y;
	while ( --n )
	{
		cin >> x >> y;
		if ( max_x < x ) max_x = x;
		else if ( min_x > x ) min_x = x;
		if ( max_y < y ) max_y = y;
		else if( min_y > y ) min_y = y;  
	}
	cout << (max_x - min_x) * (max_y - min_y) << endl;
	
	
	return 0;
}
