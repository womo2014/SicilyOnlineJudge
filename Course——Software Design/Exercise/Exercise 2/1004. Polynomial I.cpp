#include <iostream>
using namespace std;
int main()
{
	int a1, b1, a2, b2;
	cin >> a1 >> b1;
	cin	>> a2 >> b2;
	cout << a1*a2 << "x^2+" 
		 << a1*b2 + a2*b1
		 << "x+" << b1*b2 << endl;
	return 0;
}
