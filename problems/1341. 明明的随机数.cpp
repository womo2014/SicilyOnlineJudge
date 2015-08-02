//1341. 明明的随机数
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	while ( cin >> n )
	{
		int num[n];
		int i;
		for ( i = 0; i < n; i++ )
		{
			cin >> num[i];
		}
		sort(num,num+n);
		for ( i = 0; i < n; i++ )
		{
			cout << num[i] << endl;
		}		
	}
	
	return 0;
} 
