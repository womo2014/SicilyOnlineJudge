#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int num = 1;
	
		while ( --n )
		{
			num = (num+1)*2;
			
		} 
		cout << num << endl;
	}
	return 0;
} 
