#include <iostream>
#include <math.h>
#include <iomanip>
int main()
{
	int A,B,C;
	double P;
	std::cin >> A >> B >> C;
	P = ( A+B+C)/2.0;
	std::cout << std::setprecision(2) << P << std::endl;
	
	std::cout << sqrt( P*(P-A)*(P-B)*(P-C) ) << std::endl;	
	return 0;
}
