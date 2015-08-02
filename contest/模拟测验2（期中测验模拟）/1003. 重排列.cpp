//1003. жьееап
#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[1001], b;
	
	for ( int i = 1; i <= n; i++ )
	{
		cin >> a[i];
	}
	for ( int i = 1; i <= n; i++ )
	{
		cin >> b;
		cout << a[b] << endl;
	}
	
	return 0;
} 
