#include <iostream>

using namespace std;

int main()
{
	char a, b, c;
	cin >> a >> b >> c;
	cout << char(a-('a' -'A'))
		<< char(b-('a' -'A')) 
		<< char(c-('a' -'A')) 
		<< endl;
	return 0;
}
