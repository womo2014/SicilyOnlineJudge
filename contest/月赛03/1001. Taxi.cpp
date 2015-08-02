#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int aInit, aUp, bInit, bDown;
		cin >> aInit >> aUp >> bInit >> bDown;
		int diff = bInit - aInit;
		int ret;
		if (diff <= 0)
			ret = aInit;
		else {
			int times = diff/(aUp+bDown);
			aInit += aUp*times;
			bInit -= bDown*times;
			if ( aInit+aUp <= bInit)
				ret = aInit+aUp;
			else ret = bInit;
		}
		cout << ret << endl;
	}
	return 0;
}
