#include <iostream>

using namespace std;

int main()
{
	int Y;
	cin >> Y;
	
	int day =1 + (Y-2001)*365+(Y-2001)/4;
	cout << day % 7 << endl;
	return 0;
}
