#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	string a;
	while (cin >> a)
	{
		cout << "test" << endl;
		string b;
		for (int i = 1; i <= a.size(); ++i)
		{
			if ( a.size() % i != 0 ) continue;
			b =  a.substr(0,i);
			int check = 1;
			for (int j = i; j+i <= a.size(); j += i)
			{
				if ( b != a.substr(j,i)) 
				{
					check = 0;
					break;
				}
			}
			if ( check == 1 )
			{
				cout << b << endl;
				break;
			}
		}
	}


	return 0;
}