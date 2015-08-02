#include <iostream>
using namespace std;
int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int num[5] = {1, 2, 3, 4, 5,};
	for ( int i = 0; i < 5; i++ ) {
		int ret = 1;
		if ( num[i] == a) 
		ret = 0;
		if ( num[i] == b) 
		ret = 0;
		if ( num[i] == c) 
		ret = 0;
		if ( num[i] == d) 
		ret = 0;
		if (ret) {
			cout << num[i] << endl;
			break;
		}
	}
	return 0;
}
