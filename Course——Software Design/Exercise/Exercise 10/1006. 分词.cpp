#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	string a;
	while ( getline(cin, a)){
		for ( int i = 0; i < a.size(); i++ )
		{
			if ( isalpha(a[i]) )
			{
				while ( isalpha(a[i]) ){
					printf("%c",a[i]);
					i++;
				}
				printf("\n");
			}
		}
		printf("\n");
	} 
	
	return 0;
}
