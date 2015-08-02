#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iomanip>

using namespace std;

int main()
{
	char a[205];
	char b[205];
	
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s %s",a, b);
		int i, j;
		for ( i = strlen(a)-1,j = strlen(b)-1; j >= 0; j--,i-- )
		{
			a[i] -= b[j]-'0';
		}
		for ( i = strlen(a)-1; i > 0; i-- )
		{
			while ( a[i] < '0')
			{
				a[i] += 10;
				a[i-1]--;
			}
		}
		i = 0;
		while (a[i] == '0' && i < strlen(a)-1)i++;
		for (; i < strlen(a); i++ )
		{
			printf("%c",a[i]); 
		}
		printf("\n");
	}
	return 0;
}
