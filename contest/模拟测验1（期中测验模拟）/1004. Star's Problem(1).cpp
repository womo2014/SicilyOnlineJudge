#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main()
{
	int n, m;
	scanf("%d %d",&n, &m);
	
	int num[100000];
	int operation[100000];
	int x[100000];
	long long sum[100000];
	for (int i = 0; i < n; i++ )
	  scanf("%lld",&num[i]);

	int cnt = 99999, cnt1 = 0, cnt2 = 99999;
	
	for (int i = 0; i < m; i++ )
	{
	  scanf("%d",&operation[i]);
	  
	  if ( operation[i] == 2 )
	  {
	      scanf("%d",&x[cnt--]);
	  }
	  else if ( operation[i] == 3 )
	  {
	      int a, b;
			scanf("%d %d",&a, &b);
	      for ( int j = a-1; j < b; j++ )
	  			sum[cnt1] += num[j];
			x[cnt1] = b-a+1;
			cnt1++;
	  }
	}
	
	int count = 0;
	int i = 0;
	for ( int i = 0; i < m; i++)
	{
		if ( operation[i] == 1 )
	   {
//         int ccc = 0;
//         while (i < m)
//             if ( operation[i] == 1 )
//             {
//                 ccc++;
//                 i++;
//             }
//             else break;
//         if (ccc % 2 == 1)
				for ( int j = count; j < cnt1; j++ )
					sum[j] = -sum[j];
	   }
	   else if ( operation[i] == 2 )
	   {
//         long long xx = x[i];
//         while (i < m)
//             if ( operation[i] == 2 )
//             {
//                 xx += x[i];
//                 i++;
//             }
//             else break;	   	
	   	for ( int j = count; j < cnt1; j++ )
	      	sum[j] += x[cnt2--]*x[j];
	   }
	   else  {
			printf("%lld\n",sum[count++]);
//			i++;
	   }
	}
	return 0;
}                              
