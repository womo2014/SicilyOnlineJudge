#include <iostream>
using namespace std;
int max( int num[], int cnt );
int main()
{
	int n, num[4], i(0);
	while ( cin >> n && n != 0) 
	{
		for ( i = 0; i < n; i++) {
			cin >> num[i];
		}
		cout << max( num, n) << endl;		 
	}
	return 0;
}
int max( int num[], int cnt )
{
	int max = num[0], i(0);
	for ( i = 1; i < cnt ; i++) {
		if ( max < num[i] ) {
			max = num[i];
		}
	}
	return max;
}
