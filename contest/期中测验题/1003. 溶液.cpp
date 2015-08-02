#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{

	int  v;
	double c;
	string ch;
	cin >> v >> c;
	
	double m = c*v*0.01;
	double c1, m1;
	int v1;
	int n;
	cin >> n;
	cout << fixed << setprecision(5);
	while ( n-- )
	{
		cin >> ch;
		if ( ch == "P" )
		{
			cin >> v1 >> c1;
			m1 = c1*v1*0.01;
			v += v1;
			m += m1;
		}
		else {
			v -= v1;
			m -= m1;
		}
		cout << v << ' ' << 100*m/v << endl; 
	}
	
	return 0;
}
