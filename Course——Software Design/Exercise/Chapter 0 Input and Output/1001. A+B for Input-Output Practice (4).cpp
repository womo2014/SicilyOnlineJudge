#include <iostream>
using namespace std;
int main()
{
	int n, a,  sum, i;
	while(true) {
		sum = 0;
		cin >> n;
		if( n == 0) {
			break;
		}
		for ( i = 0; i < n; i++) {
			cin >> a;
			sum += a;
		}
		cout << sum << endl;
		sum = 0;
	}
	return 0;
}

