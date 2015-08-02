#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	
	cin >> n;
	
	while ( n-- )
	{
		int m;
		string a;
		cin >> m >> a;
		int i = 0;
		for ( i = 0; i < a.size(); i++ )
		{
			if ( i+1 != m )
			{
				cout << a[i];
			}
		}
		cout << endl;
	}
	return 0;
}
