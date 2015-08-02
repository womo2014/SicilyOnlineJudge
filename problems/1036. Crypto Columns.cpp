//1036. Crypto Columns
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string key;
	while ( cin >> key && key != "THEEND")
	{
		string code;
		cin >> code;
		
		int column = key.size();
		int row = code.size()/column;
		char word[row][column];
		int i, j, k;
		int cnt = 0;
		int count = 0;
		
		for ( i = 'A'; i <= 'Z' && count < key.size(); i++ )
		{
			for ( j = 0; j < key.size(); j++ )
			{
				if ( int(key[j]) == i )
				{
					for ( k = 0; k < row; k++ )
						word[k][j] = code[cnt++];
					count++;
				}
			}
		}
		
		for ( i = 0; i < row; i++ )
			for ( j = 0; j < column; j++ )
			{
				cout << word[i][j]; 
			}

		cout << endl;		
	}
	return 0;
} 
