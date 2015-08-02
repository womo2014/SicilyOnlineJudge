#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
if ( 1);
using namespace std;
long long cnt = 0;

//���ж�����������a[first...mid]��a[mid...last]�ϲ���
void mergearray(int a[], int first, int mid, int last, int temp[])
{
	int i = first, j = mid + 1;
	int m = mid,   n = last;
	int k = 0;
	while (i <= m && j <= n)
	{
		if (a[i] <= a[j])
		{
			temp[k++] = a[i++];
		}
		else
		{
			cnt += m-i+1;
			temp[k++] = a[j++];
		}
	}
	
	while (i <= m)
	{
		temp[k++] = a[i++];
	}
	
	while (j <= n)
		temp[k++] = a[j++];
	
	for (i = 0; i < k; i++)
		a[first + i] = temp[i];
}
void MergeSort(int a[], int first, int last, int temp[])
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		MergeSort(a, first, mid, temp);    //�������
		MergeSort(a, mid + 1, last, temp); //�ұ�����
		mergearray(a, first, mid, last, temp); //�ٽ������������кϲ�
	}
}
using namespace std;
int a[1000006];
int b[1000006];
int main()
{
	int n;
	cin >> n;

	for ( int i = 0; i < n; i++ )
	{
		scanf("%d",&a[i]);
	}
	MergeSort(a,0,n-1,b);
	cout << cnt << endl;

	return 0;
}
