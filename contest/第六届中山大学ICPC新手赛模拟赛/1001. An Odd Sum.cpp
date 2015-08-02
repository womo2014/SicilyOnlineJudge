#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int x[1000000];

int main()
{
    int n;
    cin >> n;
    int num;
    
    while ( n-- )
    {
        scanf("%d",&num);
        int cnt = 0;
        for ( int i = 2; i <= sqrt(num); i++)
        {
            if ( num % i == 0 ) x[cnt++] = i;
        }
        if ( cnt == 0 ) printf("%d: impossible\n",num);
        else 
		  {
			  for ( int i = cnt-1; i >= 0; i-- )
	        {
	            int t = num / x[i];
	            if ( t & 1 )
	            {
	
	                if ( x[i] & 1 )
	                {
	                	printf("%d: [%d, %d]\n",num,t-(x[i]/2)*2 ,t+(x[i]/2)*2 );
	                }
	                else printf("%d: [%d, %d]\n",num,t-x[i]/2 ,t+x[i]/2 );
	            }
	            else {
	                printf("%d: [%d, %d]\n",num, t-x[i]+1, t + x[i]-1);
	            }
	        }
	        for ( int i = cnt-1; i >= 0; i-- )
	        {
	            int t = num / x[i];
	            if ( x[i] == t )continue;
	            int m = t;
	            t = x[i];
	            x[i] = m;
	            if ( t & 1 )
	            {
						 
	                if ( x[i] & 1 )
	                {
	                	if ( t <= (x[i]/2)*2 )break;
	                	printf("%d: [%d, %d]\n",num,t-(x[i]/2)*2 ,t+(x[i]/2)*2 );
	                }
	                else {
	                if ( t-x[i]/2 <= 0 )break;
						 printf("%d: [%d, %d]\n",num,t-x[i]/2 ,t+x[i]/2 );
	                
	             }
	            }
	            else {
	            	 if ( x[i] & 1)
	                {
	                	if ( t-x[i]+1 < 0)break;
	                	printf("%d: [%d, %d]\n",num, t-x[i]+1, t + x[i]-1);
	                }
	                else 
						 {
						 	if (  t-x[i]/2< 0)break;
						 	printf("%d: [%d, %d]\n",num, t-x[i]/2, t + x[i]/2);
						 }
	            }
	        }
     	  }
    }
    return 0;
}
