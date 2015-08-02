#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while ( t-- )
	{
		int x, y, z;
		scanf("%d:%d",&x,&y);
		int a = x*60 + y;
		scanf("%d:%d",&x,&y);
		int b = x*60 + y;
		if ( b < a ) b += 24*60;
		int ret = b-a;
		printf("%02d:%02d\n",ret/60,ret%60);
	}
	return 0;
}

