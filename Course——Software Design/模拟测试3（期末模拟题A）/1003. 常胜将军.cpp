#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int n = 21;
	int step;
	for (int i = 0; i < 4; ++i)
	{
		cin >> step;
		cout << 5-step << ' ' << (n -= 5) << endl;
	}
	cout << "Game Over!" << endl;

	return 0;
}