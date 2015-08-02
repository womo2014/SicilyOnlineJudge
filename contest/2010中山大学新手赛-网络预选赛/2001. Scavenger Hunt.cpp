#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	int p, q;
	int pf[6000], qf[6000];
	scanf("%d %d",&p,&q); 
	
	int cnt1 = 0;
	for ( int i = 1; i <= p; i++ )
		if ( p % i == 0)
			pf[cnt1++] = i;
	
	int cnt2 = 0;
	for ( int i = 1; i <= q; i++ )
		if ( q % i == 0 )
			qf[cnt2++] = i;
			
	for ( int i = 0; i < cnt1; i++ )
		for ( int j = 0; j < cnt2; j++ )
			printf("%d %d\n",pf[i],qf[j]);
	
	return 0;
}
