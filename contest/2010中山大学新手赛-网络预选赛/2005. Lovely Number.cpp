#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	int n;
	while ( scanf("%d", &n) != EOF )
	{
		int t;
		int ret;
		scanf("%d",&ret);
		while ( --n )
		{
			scanf("%d",&t);
			ret = ret^t;
		}
		printf("%d\n",ret);
	}
	
	return 0;
}
