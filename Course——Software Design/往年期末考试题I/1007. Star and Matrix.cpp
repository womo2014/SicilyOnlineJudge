#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int num[10001], cnt[10001];
int tot;
bool check(int d)
{
	for ( int i = 1; i < tot; i++ )
		if ( abs(num[i]-num[0]) % d != 0 ) return false;
	return true;
}
int main()
{
	int m,n,d;
	cin >> m >> n >> d;
	tot = m*n;
	for ( int i = 0; i < tot; i++ )
		scanf("%d",&num[i]);
	if ( !check(d) ) printf("-1\n");
	else {
		sort(num,num+tot);
		int count = 0;
		for ( int i = 0; i < tot; i++ )
		{
			count += abs(num[i]-num[tot/2])/d;
		}
		printf("%d\n",count);
	}

	return 0;
}