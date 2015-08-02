#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int getNum(int y1,int m1,int d1,int y2,int m2,int d2)
{
	int n = 0;
	if (y1 <= y2 )
	{
		if ( m1 == 2 && d1 == 29 )
		{
			for ( int i = y1; i < y2; i += 4)
			{
				if ( i % 100 != 0 || i % 400 == 0)
					n++;
			}
			if ( y2 % 4 == 0 )
				if ( y2 % 100 != 0 || y2 % 400 == 0)
					if ( m2 > m1 || (m2 == m1 && d2 == d1))
						n++;
		}
		else {
			n += y2-y1;
			if ( m2 > m1 || (m2 == m1 && d2 >= d1))
				n++;	
		}
	}
	return n;
}

int main()
{
	int y1, m1, d1, y2, m2, d2;
	cin >> y1 >> m1 >> d1 >> y2 >>m2 >> d2;
	cout << getNum(y1,m1,d1, y2, m2, d2) << endl;
	
	return 0;
}
