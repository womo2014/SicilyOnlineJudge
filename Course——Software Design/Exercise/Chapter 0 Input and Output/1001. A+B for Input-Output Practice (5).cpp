#include <iostream>
using namespace std;
int main()
{
	int n, a, b, sum, i, j;
	cin >> n;
	for ( i = 0; i < n; i++) {
		sum = 0;
		cin >> a;
		for ( j = 0; j < a; j++) {
			cin >> b;
			sum += b;
		}
		cout << sum << endl;
		if ( i < n-1 ) {
			cout << endl;
		}
		sum = 0;
	}
	return 0;
}
