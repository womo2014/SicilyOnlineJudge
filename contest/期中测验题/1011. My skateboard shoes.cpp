#include <iostream>
#include <cstdio>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int a, t;
	double s = 0;
	int v = 0;
	while ( n-- )
	{
		cin >> t >> a;
		s += v*t + 0.5*a*t*t;
		v += a*t;
	}
	cout << fixed << setprecision(2);
	cout << s << endl;
	
	return 0;
}
