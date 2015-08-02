#include <iostream>
#include <string>

using namespace std;

int main()
{
	string ISBN;
	while (cin >> ISBN)
	{
		int number = 0;
		int i;
		int a(10);
		for (i = 0; i < 11; i++)
		{
			if ( ISBN[i] != '-')
			{
				number += a*(ISBN[i] - '1' + 1);
				a--;
			}
		}
		cout << ISBN << '-' ;
		int b = number % 11;
		if (b == 0)
		{
			cout << b;
		}
		else if ( b == 1)
		{
			cout << 'X';
		} else
		{
			cout << 11 - b;
		}
		cout << endl;
	}
	
	return 0;
} 
