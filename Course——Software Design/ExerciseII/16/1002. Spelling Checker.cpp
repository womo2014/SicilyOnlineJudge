#include <iostream>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

bool check(string a, string b)
{
	for(int i = 0; i < a.size()-1; i++) {
		swap(a[i], a[i+1]);
		if ( a == b )
			return true;
		swap(a[i], a[i+1]);
	}
	return false;
}

int main()
{
	map<string, string> sMap;
	int n;
	cin >> n;
	while (n--) {
		string a, b;
		cin >> a;
		b = a;
		sort(b.begin(), b.end());
		sMap[b] = a;
	}
	cin >> n;
	while ( n-- ) {
		string a, b;
		cin >> a;
		b = a;
		sort(b.begin(), b.end());
		if (sMap.find(b) != sMap.end()) {
			if (sMap[b] == a)
				cout << "Word is spelled correctly." << endl;
			else if (check(a, sMap[b]))
				cout << "Word is not spelled correctly. Did you mean \""+sMap[b]+"?\"." << endl;
			else cout << "Word is not spelled correctly." << endl;
		}
		else cout << "Word is not spelled correctly." << endl;
	}
	
	return 0;
} 
