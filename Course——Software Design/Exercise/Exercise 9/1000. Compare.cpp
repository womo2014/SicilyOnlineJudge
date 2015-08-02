#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <cstring>
using namespace std;

int main()
{
	double a, b;
	cin >> a >> b;
	if ( fabs(a-b) <= pow(10,-6))
		cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
