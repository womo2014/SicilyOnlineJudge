#include <iostream>
//#include <>
using namespace  std;

int main()
{
	int a, b, c;
	while (cin >> a >> b >> c) {
		int cnt = 1;
		int fuck = a%b;
		
		while(fuck != c) {
			fuck = (fuck*(a%b))%b;
			cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}
