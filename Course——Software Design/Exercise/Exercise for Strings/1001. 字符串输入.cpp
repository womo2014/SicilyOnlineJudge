//1001. ×Ö·û´®ÊäÈë
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a, b;
	int n;
	while ( cin >> a )
	{
		cin >> n >> b;
		int i, j;
		for ( i = a.size() - 1; i >= 0; i-- )
		{
			if ( i == n-1 )
			{
				for ( j = b.size() - 1; j >= 0; j-- )
				{
					cout << b[j];
				}
			}
			cout << a[i];
		}
		cout << endl;
	}
} 
