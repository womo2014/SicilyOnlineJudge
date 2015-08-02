//1001. Maximum again
#include <iostream>

using namespace std;

int main()
{
	int n, a, max;
	cin >> n;
	cin >> a;
	max = a; 
	while ( --n )
	{
		cin >> a;
		if ( max < a )
		{
			max = a;
		}
	}
	cout << max << endl;
	
	return 0;
}
