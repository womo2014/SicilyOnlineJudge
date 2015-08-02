#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n(0) ,i(0), score(0), cnt(1);
	char mark = 0;
	cin >> n;
	getchar();
	for ( i = 0; i < n; i++) {
		while ( (mark = getchar()) && mark != '\n') //&&和=的优先级问题 
		{
			if ( mark == 'O') {
				score += cnt++;
			}
			else cnt = 1;
		}
		cout << score << endl;
		score = 0;
		cnt = 1;
	}	
	return 0;
}
