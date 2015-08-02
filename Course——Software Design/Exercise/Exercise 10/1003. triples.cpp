#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int num[1000000+5];

int b_search(int low, int high, int key)
{
	int mid = (low+high)/2;
	if ( low > high )return -1;
	else if ( num[mid] == key ) return 1;
	else if ( num[mid] > key ) return b_search(low, mid-1, key);
	else return b_search(mid+1, high, key);
}

int main()
{
	int n, m;
	scanf("%d %d",&n, &m);
	
	int a, b, c;
	
	for ( int i = 0; i < n; i++ )
	{
		scanf("%d %d %d",&a,&b,&c);
		num[i] = a*1000000 + b*1000 + c;
	}
	sort(num, num+n);
//	for ( int i = 0; i < n; i++ )
//		printf( "%d ",num[i]);
//	printf("\n");
	
	while ( m-- )
	{
		scanf("%d %d %d",&a, &b, &c);
		int flag = 1;int tri = a*1000000 + b*1000 + c;
		for( int i = 0; i < n; i++ )
			if ( num[i] == tri){
				flag = 0;
				break;
			}
		if (flag == 0 )
			printf("Yes\n");
		else printf("No\n");
	}
	
	return 0;
}
