#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

double change( double n )
{
	if ( n >= 85 ) return 4.0;
	if ( n >= 80 ) return 3.5;
	if ( n >= 75 ) return 3.0;
	if ( n >= 70 ) return 2.5;
	if ( n >= 60 ) return 2.0;
}
double maxi,mini;
int sel[9] = {60, 69, 70, 74, 75, 79, 80, 85, 100};
void dfs(int last, int cur, int rest, double scale )
{
	if ( cur == 1 )
	{
		scale += change(rest);
		if ( scale > maxi ) maxi = scale;
		if ( scale < mini ) mini = scale;
	}
	else for ( int i = 0; i < 9; i++ )
	{
		int t = sel[i];
		if ( t >= last && rest-t >= 60*(cur-1) && rest-t <= 100*(cur-1) )
			dfs(t, cur-1,rest-t, scale+change(t) );
	}

}

int main()
{
	int t;
	cin >> t;
	while ( t-- )
	{
		int score, n;
		cin >> score >> n;
		int sum = score*n;
		maxi = mini = change(score)*n;
		dfs(0,n,sum,0);
		printf("%.4f %.4f\n",mini/n, maxi/n);
	}

	return 0;
}