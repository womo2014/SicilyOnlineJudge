#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
	double x1, y1, r1, x2, y2, r2;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	
	double d = sqrt( (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2) );
	double r = r1 + r2;
	double rr = fabs( r1-r2);
	
	if ( d == 0 && r1 == r2 )
		cout << "coincide";
	else if ( d < rr )
		cout << "containing";
	else if ( d == rr )
		cout << "internally-tangent";
	else if ( d < r )
		cout << "intersection";
	else if ( d == r )
		cout << "externally-tangent";
	else cout << "disjoint";
	
	cout << endl;
	
	return 0;
}
