#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for ( int i = n-1; i >= 0; i-- )
	{
		for ( int j = i; j < n-1;j++)cout << "     ";
		for ( int j = 0; j <= i; j++)printf("%5d",1<<j);
		for ( int j = i-1; j >= 0; j-- )printf("%5d",1<<j );
		cout << endl;
	}
  return 0;
}




