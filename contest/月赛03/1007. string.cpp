#include <iostream>
using namespace std;

int main()
{
	string a, b;
	int t;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		int flag = 1;
		for(int i = 0; i < b.size(); i++) {
			if ( a.substr(0,a.size()-i) == b.substr(i) && a.substr(a.size()-i) == b.substr(0,i)) {
				cout << "Yes" << endl;
				flag = 0;
				break;
			}
		}
		if (flag)
			cout << "No" << endl;
	}
	return 0;
} 
