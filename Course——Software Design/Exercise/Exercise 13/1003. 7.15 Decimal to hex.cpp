#include <iostream>
#include <cstring>
#include <string>

using namespace std;

char * convertDecimalToHex(int value)
{
	char *s = new char[10];
	int digit[10];
	int cnt = 0;
	while ( value )
	{
		digit[cnt++] = value % 16;
		value /= 16;
	}
	int cnt2 = 0;
	while ( cnt-- )
	{
		if ( digit[cnt] < 10 ) s[cnt2] = digit[cnt]+'0';
		else s[cnt2] = digit[cnt]-10+'A';
		cnt2++;
	}
	s[cnt2] = '\0';
	return s;
}
void convertDecimalToHex(int value, char *s)
{
	int digit[10];
	int cnt = 0;
	while ( value )
	{
		digit[cnt++] = value % 16;
		value /= 16;
	}
	int cnt2 = 0;
	while ( cnt-- )
	{
		if ( digit[cnt] < 10 ) s[cnt2] = digit[cnt]+'0';
		else s[cnt2] = digit[cnt]-10+'A';
		cnt2++;
	}
	s[cnt2] = '\0';
}

int main()
{
	int n;
	cin >> n;
	cout << convertDecimalToHex(n) << endl; 
	char s[10];
	convertDecimalToHex(n,s);
	cout << s << endl; 
	
	return 0;
}
