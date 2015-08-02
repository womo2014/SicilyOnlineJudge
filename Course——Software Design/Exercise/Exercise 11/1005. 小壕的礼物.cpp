#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	
	int cnt = 0;
	int num;
	string gift[100];
	string name;
	
	while ( n-- )
	{
		cin >> num;
		if ( num == 1 )
		{
			cin >> gift[++cnt];
		}
		else {
			cin >> name;
			cout << name << ' ' << gift[cnt--] << endl;
		}
	}
	
	return 0;
}
