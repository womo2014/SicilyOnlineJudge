//1004. Power
#include <iostream>
#include <iomanip> 
using namespace std;

int main()
{
	int n; 
	cin >> n;
	
	int high[100] = {3, };
	
	while ( --n )
	{
		for ( int i = 0; i < 100; i++ )
			high[i] = high[i]*3;
		for ( int i = 0; i < 99; i++ )
		{
			high[i+1] += high[i]/10000;
			high[i] %= 10000;
		}
	}
	int i = 99;
	while ( high[i] == 0 ) i--;
	cout << high[i--];
	cout << setfill('0');
	for ( ; i >= 0; i-- )
		cout << setw(4) << high[i];
	cout << endl;
	
	return 0;
}
