#include <iostream>
using namespace std;
int main()
{
	int n(0);
	cin >> n;
	int a, b;
	int i(0);
	for ( i = 0; i < n; i++) {
		cin >> a >>b;
		cout << a + b << endl;
	}
	return 0;
}
