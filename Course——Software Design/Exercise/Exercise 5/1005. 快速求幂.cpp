//1005. ¿ìËÙÇóÃİ
#include <iostream>

using namespace std;
int my_pow_mod(int a, int b, int p);
int main()
{
	int a, b, p;
	cin >> a >> b >> p;
	cout << my_pow_mod(a, b, p) << endl;
	return 0;
}

int my_pow_mod(int a, int b, int p )
{
	int ret;
	if ( b == 0 || b == 1 )
		ret = a % p;
	else if ( b % 2 == 0 )
	{
		int x = my_pow_mod(a, b/2, p);
		ret = (x * x) % p;
	}
	else
		ret = (my_pow_mod(a, b-1, p) * a%p) % p;
	
	return ret;
}
