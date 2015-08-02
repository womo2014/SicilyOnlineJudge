#include <iostream>
#include <map>
#include <cstring>
#include <string>
using namespace std;
string a[100];
string b[100];
string c[100];
int main()
{
	int cnt = 0;
	while ( getline(cin,a[cnt]) )
	{
		int i = a[cnt].find_first_of(',');
		b[cnt] = a[cnt].substr(0,i);
		c[cnt] = a[cnt].substr(i+2);
		cnt++;
	}
	for ( int i = 0; i < cnt; i++ )
	{
		cout << "mymap[\"" << b[i] << "\"] = \"" << c[i] << "\";" << endl; 
	}
	return 0;
} 
