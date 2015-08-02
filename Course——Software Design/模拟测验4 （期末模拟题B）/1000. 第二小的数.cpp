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
	int num[101];
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> num[i];
	}
	sort(num,num+n);
	cout << num[1] << endl;
  return 0;
}




