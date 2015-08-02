#include <cstdio>

int main()
{
    int n, m;
    scanf("%d %d",&n, &m);
    
    long long num[100001] = {0, };
    
	 for ( int i = 1; i <= n; i++ )
    {
    	scanf("%lld",&num[i]);
    	num[i] += num[i-1]; 
    }
        
    long long add = 0;
	 int sign = 1;    
    int operation;
    while ( m-- )
    {
        scanf("%d", &operation);
        if ( operation == 1 )
        {
            add *= -1;
            sign *= -1;
                
        }
        else if ( operation == 2 )
        {
            int x;
            scanf("%d",&x);
				add += x;
        }
        else {
            int a, b;
            scanf("%d %d", &a, &b);
            printf("%lld\n",(num[b]-num[a-1])*sign+add*(b-a+1));
        }
    }
    return 0;
}                                 
