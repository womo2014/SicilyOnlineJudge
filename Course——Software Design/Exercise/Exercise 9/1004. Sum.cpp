#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <cstring>
using namespace std;

int main()
{
	int n, m, l, r;
	cin >> n >> m;
	int num[100005];
	long long sum[100005];
	scanf("%d", &num[1]);
	sum[1] = num[1]; 
	sum[0] = 0;
	for ( int i = 2; i <= n; i++ )
	{
		scanf("%d", &num[i]);
		sum[i] = sum[i-1] + num[i]; 
	}
	while ( m-- )
	{
		int l, r;
		scanf("%d %d", &l, &r);
		printf("%lld\n", sum[r]-sum[l-1]);
	}
	return 0;
}
