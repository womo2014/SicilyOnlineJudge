#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;
	string prefix;
	for ( int i = 0; 
			i < a.size() && i < b.size() && a[i] == b[i];
			i++ )
	{
		prefix.push_back(a[i]);
	}
	if ( prefix.empty() )
		cout << "no common prefix" << endl;
	else
		cout << prefix << endl; 
	return 0;
}
