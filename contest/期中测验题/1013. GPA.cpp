#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

string l( double a )
{
	string x = "A";
	if ( a < 1.0 ) x = 'F';
	else if ( a < 1.8 ) x = 'E';
	else if ( a < 2.6 ) x = 'D';
	else if ( a < 3.4 ) x = 'C';
	else if ( a < 4.2) x = 'B';
	
	return x;
}
int main()
{
	double a, b;
	cin >> a >> b;
	if ( l(a) == l(b) )
		cout << "NO" << endl;
	else cout << "YES" << endl;
	return 0;
}
