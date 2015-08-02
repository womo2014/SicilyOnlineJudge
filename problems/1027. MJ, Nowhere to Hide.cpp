//1027. MJ, Nowhere to Hide
#include <iostream>
#include <string>

using namespace std; 

int main()
{
	int n;
	string id[20];
	string ip[20];
	
	cin >> n;
	while ( n != 0)
	{
		int i;
		for ( i = 0; i < n; i++ )
		{
			cin >> id[i] >> ip[i];
		}
		int cnt;
		int j = 0;
		for ( cnt = 0; cnt < n/2; j++ )
		{
			for ( i = j+1; i < n; i++ )
			{
				if ( ip[i] == ip[j] )
				{
					cout << id[i] 
						 << " is the MaJia of " 
					     << id[j] << endl;
					cnt++;
					break;
				}
			}	
		}
		cout << endl;
		cin >> n;

	}	
	return 0;
}
