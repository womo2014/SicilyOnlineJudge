#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <cstring>
using namespace std;

void reversal(int num[], int l, int r)
{
	int tmp[1005];
	int i,j;
	for (i = l; i <= r;i++)
		tmp[i] = num[i];
	for ( i = l, j = r; i <= r;i++,j--)
		num[i] = tmp[j];
}

int main()
{
	int n, m, l, r;
	cin >> n >> m;
	int num[1005];
	
	for ( int i = 1; i <= n; i++ )
		scanf("%d", &num[i]);
	
	while ( m-- )
	{
		scanf("%d %d",&l, &r);
		reversal(num, l, r);
	}
	
	for ( int i = 1; i < n; i++ )
		printf("%d ",num[i]);
	printf("%d\n",num[n]);
	return 0;
}
