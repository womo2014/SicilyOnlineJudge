#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;
void multiply(char* a, char* b, char* c)
{
	int i, j, ca, cb, *s;
	ca = strlen(a);
	cb = strlen(b);
	s = new int[ca+cb];
	memset(s,0,sizeof(int)*(ca+cb));	
	for (i = 0; i < ca; i++)
		for(j = 0; j < cb; j++)
			s[i+j+1] += (a[i]-'0')*(b[j]-'0');
	
	for (i = ca+cb-1; i >= 0; i--)
		if(s[i] >= 10)
		{
			s[i-1] += s[i]/10;
			s[i] %= 10;
		}	
	i = 0;
	while ( s[i] == 0 && i < ca+cb-1 )i++;
	for (j = 0; i < ca+cb; i++,j++)
		c[j] = s[i]+'0';
	c[j] = '\0';
	delete[] s;
}
int main()
{
	int n;
	cin >> n;
	char a[102];
	char b[10];
	char c[202];
	while ( n-- )
	{
		cin >> a >> b;
		multiply(a, b, c);
		printf("%s\n", c);
	}
	return 0;
}