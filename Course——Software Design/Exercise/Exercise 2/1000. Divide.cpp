#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	int c(1);
	while ( c*b <= a) {
		c++;
	}
	cout << c-1 << endl << fixed 
		 << setprecision(2)
		 << (double)a/b << endl;
	return 0;
}
