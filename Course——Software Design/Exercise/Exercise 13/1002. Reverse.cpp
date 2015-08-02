#include <string>
#include <iostream>
#include <cstring>

using namespace std; 

char * prefix(const char * const s1, const char * const s2)
{
	char *a = new char[100];
	int i = 0;
	for ( i = 0; i < strlen(s1) && i < strlen(s2); i++ )
	{
		if ( s1[i] == s2[i] )
		{
			a[i] = s1[i];
		}
		else {
			a[i] = '\0';
			return a;
		}
	}
	a[i] = '\0';
	return a;
}
int main()
{
	char a[100],b[100];
	std::cin >> a >> b;
	std::cout << prefix(a,b) << std::endl;
}
