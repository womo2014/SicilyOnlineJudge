#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	double ah,ap, ai,bh,bp,bi,ch,cp,ci;
	ai = bi = ci = ah = ap = bh = bp = ch = cp = 0;
	int n;
	cin >> n;
	int tj, tp;
	double th;
	for ( int i = 1; i <= n; i++ )
	{
		scanf("%d %d",&tj, &tp);
		th = 1.0*tj/tp;
		if ( ah < th )
		{
			ch = bh;
			cp = bp;
			ci = bi;
			bh = ah;
			bp = ap;
			bi = ai;
			ah = th;
			ap = tp;
			ai = i;
		}
		else if ( bh < th )
		{
			ch = bh;
			cp = bp;
			ci = bi;
			bh = th;
			bp = tp;
			bi = i;
		}
		else if ( ch < th )
		{
			ch = th;
			cp = tp;
			ci = i;
		}
	}
	cout << ap+bp+cp << endl;
	cout << ai << endl;
	cout << bi << endl;
	cout << ci << endl; 
	return 0;
}
