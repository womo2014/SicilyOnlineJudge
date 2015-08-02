#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int a;
	cin >> a;
	double b = 80000.0/a;
	int c = b+0.9999999;
	cout << c << endl;
	return 0;
}