//1000. Easy job
#include <iostream>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	int i;
	for ( i = a; i <= b; i++ )
	{
		if ( i % 2 != 0 )
		{
			cout << i << endl;
		} 
	}
	return 0;
}
