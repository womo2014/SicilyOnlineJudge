#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int maxi = 0;

struct BiTNode{
    char data;
    struct BiTNode *first, *next;
} trees[80000], *tree[80000] ;

int val[80000];

int path( BiTNode *m, int top, int cnt)
{
	if ( m->data > top )
	{
		cnt++;
		top = m->data;
		int t, mcnt = cnt;
		if ( m->first != NULL )
		{	
			
			int value = m->data;
			m = m->first;
			t = path(m,top,cnt);
			if ( mcnt < t ) mcnt = t;
			while ( m->next != NULL )
			{
				t = path(m->next,top,cnt);
				if ( mcnt < t ) mcnt = t;
				m = m->next;
			}
		}
		return mcnt;
	}
	else {
		int t = path(m,-1,0);
		if ( maxi < t ) maxi = t;
		return cnt;
	}
}

int main()
{
	int k;
	scanf("%d",&k);
	for ( int i = 0; i < k; i++ )
	{
		scanf("%d",&val[i]);
		tree[i] = &trees[i];
		tree[i]->first = tree[i]->next;
	}
	tree[0]->data = val[0];
	int a, b;
	for ( int i = 1; i < k; i++ )
	{
		scanf("%d %d",&a, &b);
		if ( tree[a]->first == NULL) tree[a]->first = tree[b];
		else {
			struct BiTNode *temp = tree[a]->first;
			while ( temp->next != NULL )
			{
				temp = temp->next;
			}
			temp->next = tree[b];
		}
		tree[b]->data = val[b];
	}
	int t = path(tree[0],-1,0);
	if ( t > maxi ) maxi = t;
	printf("%d\n",maxi);
	return 0;
}
