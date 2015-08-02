#include <iostream>
#include <iomanip>
int main()
{
	long double r = 0,
	PI = 3.14159265358979;
	std::cin >> r;
	std::cout << std::fixed 
			  << std::setprecision(8) 
			  << PI*r*r 
			  << std::endl;
	return 0;
}
