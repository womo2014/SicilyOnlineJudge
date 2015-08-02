#include <iostream>

using namespace std;

int main()
{
	double p;
	cin >> p;
	
	if ( p >= 4.2 ) cout << 'A' << endl;
	else if ( p >= 3.4 ) cout << 'B' << endl;
	else if ( p >= 2.6 ) cout << 'C' << endl;
	else if ( p >= 1.8 ) cout << 'D' << endl;
	else if ( p >= 1.0 ) cout << 'E' << endl;
	else cout << 'F' << endl;
	
	return 0;
}
