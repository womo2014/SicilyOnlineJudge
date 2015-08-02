#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;
	cout << fixed << setprecision(2) 
		 << 0.5*( (x2-x1)*(y3-y1) + (y2-y1)*(x1-x3) )
		 << endl;
	return 0;
}
