#include <iostream>
using namespace std;
int main()
{
	int a, b, sum(0);
	cin >> a;
	for ( int i = 0; i < 3; i++) {
		b = a % 10;
		a /= 10;
		sum += b;
	}
	cout << sum <<endl;
	return 0;
}
