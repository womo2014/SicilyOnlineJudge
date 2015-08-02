//1004. Rich man
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int i;
	long long a, sum_e(0), sum_d(0);
	for ( i = 0; i < n; i++ )
	{
		cin >> a;
		sum_e += a;
		sum_d += a*a;	
	}
	double ex = 1.0*sum_e/n;
	double dx = 1.0*sum_d/n - ex*ex;
	cout << fixed << setprecision(2); 
	cout << ex << ' ' << dx << endl;
	return 0;
}
