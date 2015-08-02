#include <iostream>

using namespace std;

int main()
{
	double a, b, c, p, q;
	cin >> a >> b >> c >> p >> q;
	
	double g = b*b-4*a*c;
	double z = -b / (2*a);
	double fx1 = a*p*p + b*p + c;
	double fx2 = a*q*q + b*q + c;
	
	if(fx1*fx2 <= 0)
	{
		cout << "Yes" << endl;
	}
	else if( fx1 > 0 && g >= 0 
			 && z > p && z < q)
	{
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	
	return 0;
}
