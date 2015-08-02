#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{
	double a, b, c;
	cin >> a >> b >> c;
	cout << fixed << setprecision(3);
	cout << (-b-sqrt(b*b-4*a*c))/(2*a) 
		 << " "
		 << (-b+sqrt(b*b-4*a*c))/(2*a) 
		 << endl;	
	return 0;
}
