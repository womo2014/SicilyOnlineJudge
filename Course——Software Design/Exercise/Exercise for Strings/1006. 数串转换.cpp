//1006. 数串转换
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	string a;
	while ( cin >> a )
	{
		int i = 0;
		double num = 0;
		int length = a.size();
		//算出e前面的整数部分 
		while ( a[i] != '.' && a[i] != 'e' && i < length )
		{
			num = num*10 + (a[i] - '0');
			i++;
		}
		cout << a[i] << endl;
		//如果有的话，算出e前面的小数部分 
		double x = 0.1;
		if ( i < length && a[i] != 'e' )
			while ( ++i < length && a[i] != 'e' )
			{
				num += (a[i] - '0')*x;
				x /= 10;
			}
		cout << num << endl;
		//算出后面是10的多少次方 
		int cnt = 0;
		if ( i < length )
		{
			i++;
			if ( a[i] == '-' )
			{
				while ( ++i < length )
				{
					cnt = cnt*10 + (a[i] - '0'); 
				}
				cnt = -1*cnt;
			}
			else {
				while ( i < length )
				{
					cnt = cnt*10 + (a[i] - '0');
					i++;
				}
			}
		}
		//输出 
		cout << fixed << setprecision(10); 
		cout << num*pow(10, cnt) << endl;
	}
	return 0;
}
