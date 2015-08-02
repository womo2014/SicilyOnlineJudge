#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

int b_search(int arr[], int low, int high, int key)
{
	while ( low < high )
	{
		int mid = (low+high)/2;
		if ( arr[mid] == key )return mid;
		else if ( arr[mid] < key ) low = mid+1;
		else high = mid-1;
	}
}
int new_arr[200000+5];
int aa[100000+5];
int bb[100000+5];
int aaf[100000+5];
int bbf[100000+5]; 

int main()
{
	int n, m, q;
	scanf("%d %d %d", &n, &m, &q);
	int cnt = 0;
	for ( int i = 0; i < n; i++ )
		scanf("%d",&aa[i]);
	for ( int i = 0; i < m; i++ )
		scanf("%d",&bb[i]);
	int i = 0; 
	int j = 0;
	int k = 0;
	while ( i < n && j < m )
	{
		if ( aa[i] < bb[j] ) {
			new_arr[k++] = aa[i];
			aaf[i++] = j;
		}
		else {
			new_arr[k++] = bb[j];
			bbf[j++] = i;
		}
	}
	while ( i < n )
	{
		new_arr[k++] = aa[i];
		aaf[i++] = j;
	}
	while ( j < m )
	{
		new_arr[k++] = bb[j];
		bbf[j++] = i;
	}
	int *a, *b, *af, *bf;
	
	while ( q-- )
	{
		int L1, R1, L2, R2, k;
		scanf("%d %d %d %d %d", &L1, &R1, &L2, &R2, &k);
		if ( aa[L1] > bb[L2] )
		{
			swap(L1,L2); swap(R1,R2);
			a = bb; b = aa; af = aaf; bf = bbf;
		}
		else {
			a = aa;b = bb; af = aaf; bf = bbf;
		}
		
		if ( a[R1] < b[L2] )
		{
			int len = R1-L1+1;
			if ( k <= len )
				printf("%d\n",a[L1+k-1]);
			else 
				printf("%d\n",b[L2+k-len-1]);
		}
		else 
		{
			int x = bf[L2]-1;
			int len = x-L1+1;
			if ( k <= len )
				printf("%d\n",a[L1+k-1]);
			else {
				k -= len;
				int left = b_search(new_arr,0,m+n-1,b[L2]);
				if ( a[R1] < b[R2] )
				{
					int right = b_search(new_arr,0,m+n-1,a[R1]);
					len = right-left+1;
					if ( k <= len )
						printf("%d\n",new_arr[left+k-1]);
					else 
						printf("%d\n",b[af[R1]+k-len-1]);
				}
				else {
					int right = b_search(new_arr,0,m+n-1,b[R2]);
					len = right-left+1;
					if ( k <= len )
						printf("%d\n",new_arr[left+k-1]);
					else 
						printf("%d\n",a[bf[R2]+k-len-1]);
				}
			}
		}
	}
	return 0;
} 

