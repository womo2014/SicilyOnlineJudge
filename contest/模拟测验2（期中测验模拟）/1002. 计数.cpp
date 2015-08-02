//1002. ¼ÆÊı 
#include <iostream>

using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	
	int n;
	cin >> n;
	
	while ( n-- )
	{
		int num;
		cin >> num;
		int cnt = 0;
		
		while ( num )
		{
			int x = num % 10;
			if ( x == a || x == b || x == c )
				cnt++;
			num /= 10;
		}
		
		cout << cnt << endl;
	}
	
	return 0;
}
