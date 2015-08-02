#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <cstring>
using namespace std;

void hanoi( int n, int a, int b, int c)
{
	if ( n == 1) printf("%d%d\n",a,c);
	else {
		hanoi(n-1,a,c,b);
		printf("%d%d\n",a,c);
		hanoi(n-1,b,a,c);
	}
	
}

int main()
{
	int n;
	cin >> n;
	hanoi(n,1, 2, 3);
	return 0;
}
