#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <cstdlib>
using namespace std;

int dividor( char* a, int b);
int sss(char* a);

int main()
{
	int t;
	cin >> t;
	char num[150];
	for ( int i = 1; i <= t; i++)
	{
		scanf("%s",num);
		printf("Case %d: %d\n",i,sss(num));
		if ( i < t )printf("\n");
	}
	return 0;
}

int dividor( char* a, int b)
{
	int n, i, j, tmp = 0;
	n = strlen(a);
	char *s;
	s = (char*)malloc(sizeof(char)*(n+1));
//	cout << a[0]-'0' << endl;
	for ( i = 0;a[i] != '\0'; i++ )
	{
		tmp = tmp*10+a[i]-'0';
//  	cout << tmp << '@' << endl;		
		s[i] = tmp/b+'0';
		tmp %= b;
	}
//	cout << tmp << '@' << endl;
	s[i] = '\0';
	for (i = 0;s[i] == '0' && s[i] != '\0';i++);
	if ( s[i] == '\0')
	{
		a[0] = '0';
		a[1] = '\0';
	}
	else {
		for (j = 0; s[i] != '\0'; i++,j++)
			a[j] = s[i];
		a[j] = '\0';
	}
//	cout << a << "@" << tmp << endl;
	free(s);
	return tmp;
}

int sss(char* a)
{
	int bun[400];
	int cnt = 0;
	while ( strcmp(a,"1") != 0 )
	{
		bun[++cnt] = dividor(a,2);
//		cout << bun[cnt] << ' ' << a << endl;
	}
	int ret = 1;
	for ( int i = 1;i <= cnt && bun[i] != 1;i++)ret++;
	return ret;
}
