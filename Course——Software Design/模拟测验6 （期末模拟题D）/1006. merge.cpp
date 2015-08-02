#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

struct mer
{
	int x, y;
};

bool cmp(mer a, mer b)
{
	if ( a.x != b.x ) return a.x < b.x;
	return a.y < b.y;
}

int main()
{
	int n;
	cin >> n;
	mer m[100];
	for ( int i = 0; i < n; i++ )
		cin >> m[i].x >> m[i].y;
	sort(m,m+n,cmp);
	
	bool flag = false;
	mer temp = m[0];
	for ( int i = 1; i < n; i++)
	{
		if ( temp.y < m[i].x )
		{
			cout << temp.x << ' ' << temp.y << endl;
			temp = m[i];
		}
		else if ( temp.y < m[i].y )
			temp.y = m[i].y;
	}
	cout << temp.x << ' ' << temp.y << endl;		
	

	return 0;
}

