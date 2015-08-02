#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int tree[10000+5];

int main()
{
	int l, m, a, b;
	cin >> l >> m;
	for ( int i = 0; i <= l; i++ )
		tree[i] = 1;
	while ( m-- )
	{
		scanf("%d %d",&a, &b);
		for ( int i = a; i <= b; i++ )
			tree[i] = 0;
	}
	int cnt = 0;
	for ( int i = 0; i <= l; i++ )
		if ( tree[i] == 1 ) cnt++;
	cout << cnt << endl;
	
	return 0;
}
