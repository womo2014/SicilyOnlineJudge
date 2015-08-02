#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iomanip>
int a, b, c;
int f(int x);
using namespace std;

int main()
{
	int x;
	cin >> a >> b >> c >> x;
	cout << f(x) << endl;
	return 0;
}
int f(int x)
{
	if ( x <= 3 )return 1;
	else return a*f(x-1)+b*f(x-2)+c*f(x-3);
}
