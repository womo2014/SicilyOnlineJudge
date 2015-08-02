#include <iostream>
#include <string>
using namespace std;

int cnt(string str)
{
	int ret = 0;
	for(int i = 0; i < str.size(); i++) {
		for(int j = 0; i-j>=0 && i+j <str.size(); j++) {
			if(str[i+j] == str[i-j])
				++ret;
			else break;
		}
		for(int j = 0; i-j>=0 && i+j+1 <str.size(); j++) {
			if(str[i+j+1] == str[i-j])
				++ret;
			else break;
		}
	}
	return ret;
}

int main()
{
	string str;
	while (cin >> str) {
		cout << cnt(str) << endl;
	}
	return 0;
}
