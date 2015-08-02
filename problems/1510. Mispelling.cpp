#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n, i, j;
	int cnt = 0;
	cin >> n;
	string word[n], missword[n];
	int miss[n];
	for ( i = 0; i < n; i++ ) {
		cin >> miss[i] >> word[i];
		for ( j = 0; j < word[i].size(); j++ ) {
			if ( j != miss[i]-1 ) 
			missword[i].push_back( word[i][j] );
		}
		cout << i+1 << " " << missword[i] << endl;
	}

	return 0;
}
