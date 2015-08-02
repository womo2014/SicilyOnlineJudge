#include <iostream>
#include <cstdio>

using namespace std;

struct List
{
	int data;
	List *last, *next;
};

List arr[500002];

void ini(int n)
{

	for ( int i = 1; i <= n; i++ )
	{
		arr[i].data = i;
		arr[i].last = &arr[i-1];
		arr[i].next = &arr[i+1];
	}
	arr[0].next = &arr[1];
	arr[n].next = NULL;
}

int main()
{
	int t;
	cin >> t;
	int x, a, b;
	while ( t-- )
	{
		int n, m;
		scanf("%d %d",&n, &m);
		ini(n);
		while ( m-- )
		{
			scanf("%d %d %d",&x, &a, &b);
			List *ta = &arr[a], *tb = &arr[b];
			if ( x == 1 )
			{
				ta->last->next = ta->next;
				ta->next->last = ta->last;
				ta->last = tb->last;
				ta->next = tb;
				tb->last->next = ta;
				tb->last = ta;
			}
			else {
				ta->last->next = ta->next;
				ta->next->last = ta->last;
				ta->last = tb;
				ta->next = tb->next;
				if ( tb->next != NULL ) tb->next->last = ta;
				tb->next = ta;
			}
		}
		List * temp = &arr[0];
		while ( temp->next != NULL )
		{
			temp = temp->next;
			printf("%d ",temp->data);
		}
		printf("\n");

	}

	return 0;
}
