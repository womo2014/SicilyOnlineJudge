#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	int x0, y0, x1, y1, x2, y2;
	cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;
	int a = (x1-x2)*(x0-x1)+(y1-y0)*(y2-y1);
	int b = (x1-x2)*(x0-x2)+(y2-y0)*(y2-y1);
	if ( a < 0 && b > 0)
		cout << "Safe" << endl;
	else cout << "Danger" << endl;
	
	return 0;
}
