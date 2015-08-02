#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int n;
	int num[4001];
	cin >> n;
	for ( int i = 0; i < n; i++ )
	{
		cin >> num[i];
	}
	sort(num,num+n);
	bool a = true;
	int i = 0, j = n-1;
	while ( i != j )
	{
		if (a) cout << num[i++] << endl;
		else cout << num[j--] << endl;
		a = !a;
	}
	cout << num[i] << endl;
	return 0;
}