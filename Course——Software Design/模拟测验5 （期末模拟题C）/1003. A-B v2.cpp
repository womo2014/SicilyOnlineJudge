#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
	double a, b;
	while ( cin >> a >> b && !(a == 0 && b == 0))
	{
		a *= 100;
		b *= 100;
		if ( a < 0 )
		{
			int t = a;
			a = t*0.01;
		}
		else {
			int t = a+0.5;
			a = t*0.01;
		}
		int t = b;
		b = t*0.01;
		cout << a-b << endl;
	}
	return 0;
}