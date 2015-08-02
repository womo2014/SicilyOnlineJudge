#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(map<string, int>::value_type p1, map<string, int>::value_type p2) 
{
	if ( p1.second == p2.second ) return p1.first > p2.first;
	else return p1.second > p2.second;
}

int main()
{
	int n;
	
	while (cin >> n) {
		int m = 0;	
		map<string, int> count;
		while (n--) {
			string a;
			cin >> a;
			if (count.find(a) != count.end())
				count[a]++;
			else count[a] = 1;
			if ( count[a] > m)
				m = count[a]; 
		}
		cout << m << endl;
		for (map<string, int>::iterator it = count.begin();
		it != count.end(); it++) {
			if ((*it).second == m)
				cout << (*it).first << endl;
			else break;	 								
		}
	}
	return 0;
}
