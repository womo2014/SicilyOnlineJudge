#include <cstdio>
#include <vector>

using namespace std;
int main()
{
	int n, m;
	scanf("%d %d",&n, &m);
	int i, j;	
	int num[100000];
	
	vector<long long> sum;
	
	int la[100000];
	int oper[100000][2] = {0, };
	for (i = 0; i < n; i++ )
		scanf("%d",&num[i]);
	
	int cnt = 0;
	for ( i = 0; i < m; i++)
	{
		scanf("%d", &oper[i][0]);
		
		if ( oper[i][0] == 1 );
		else if ( oper[i][0] == 2 )
		{
			scanf("%d",&oper[i][1]);
		}
		else {
			int l, r;
			scanf("%d %d", &l, &r);
			long long t_sum = 0;
			for ( j = l-1; j < r; j++ )
			{
				t_sum += num[j];
			}
			sum.push_back(t_sum);		
			la[cnt++] = r-l+1;
		}
	}
	int count = 0;
	for ( i = 0; i < m; i++ )
	{
		if ( oper[i][0] == 1 )
		{
			for ( int k = count; k < n; k++ )
				sum[k] = -sum[k];
		}
		else if ( oper[i][0] == 2 )
		{
			for ( int k = count; k < n; k++ )
				sum[k] += oper[i][1]*la[k];
		}
		else {
			printf("%lld\n", sum[count++]);
		}
	}
	return 0;
}
