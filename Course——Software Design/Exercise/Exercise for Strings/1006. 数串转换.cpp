//1006. ����ת��
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
		//���eǰ����������� 
		while ( a[i] != '.' && a[i] != 'e' && i < length )
		{
			num = num*10 + (a[i] - '0');
			i++;
		}
		cout << a[i] << endl;
		//����еĻ������eǰ���С������ 
		double x = 0.1;
		if ( i < length && a[i] != 'e' )
			while ( ++i < length && a[i] != 'e' )
			{
				num += (a[i] - '0')*x;
				x /= 10;
			}
		cout << num << endl;
		//���������10�Ķ��ٴη� 
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
		//��� 
		cout << fixed << setprecision(10); 
		cout << num*pow(10, cnt) << endl;
	}
	return 0;
}
