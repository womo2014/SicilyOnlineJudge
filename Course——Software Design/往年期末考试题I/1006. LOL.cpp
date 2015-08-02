#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

struct Period
{
	int l,r;
	Period():l(0),r(0){}
};

void scan(Period &t );

int time1[86401];
int time2[86401];
int time3[86400];
int main()
{
	int n, first = 1, cnt[3];
	Period temp;
	while (scanf("%d %d %d",&cnt[0],&cnt[1],&cnt[2]) != EOF)
	{
		if ( first ) first = 0;
		else printf("\n");
		
		memset(time1,0,sizeof(time1));
		memset(time1,0,sizeof(time2));
				
		for ( int i = 0; i < 3; i++ )
			for ( int j = 0; j < cnt[i]; j++ )
			{	
				scan(temp);
				for ( int k = temp.l; k <= temp.r; k++)
					if ( time1[k] == i )time1[k]++;
			}
		
		scanf("%d",&n);
		while ( n-- )
		{
			memset(time3,0,sizeof(time3));	
			int t;
			scanf("%d",&t);
			while ( t-- )
			{
				scan(temp);
				for ( int i = temp.l; i <= temp.r; i++)
					time3[i]++;
			}
			for ( int i = 0; i < 86400; i++ )
				if ( time3[i] > 0 ) time2[i]++;	
		}


		int flag = 0;
		int left, count = 0;
		for ( int i = 0; i <= 86400; i++ )
		{
			if ( time1[i] == 3 && time2[i] >= 2 )
			{
				if ( count == 0 ) 
					left = i;
				count++;
			}
			else if ( count != 0 ) 
			{
				if ( count > 1 )
				{
					flag++;
					printf("%02d:%02d:%02d ",left/(60*60),(left%(60*60))/60,left%60);
					printf("%02d:%02d:%02d\n",(left+count-1)/(60*60),((left+count-1)%(60*60))/60,(left+count-1)%60);
				}
				count = 0;
			}
		}
		if (flag == 0 ) printf("You cannot start a game!\n");
		
	}
	return 0;
}

void scan(Period &t )
{
	int x, y, z;
	scanf("%d:%d:%d",&x,&y,&z);
	t.l = x*60*60 + y*60 + z;
	scanf("%d:%d:%d",&x,&y,&z);
	t.r = x*60*60 + y*60 + z;
}
