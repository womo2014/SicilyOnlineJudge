#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	
	while (t--) {
		bool fuck[5001] = {0};
		int n;
		cin >> n;
		int num;
		for(int i = 0; i < n; i++) {
			cin >> num;
			fuck[num] = true;
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++ )
			if (fuck[i])
				cnt++;
		cout << n-cnt << endl;
	}
	return 0;
} 
