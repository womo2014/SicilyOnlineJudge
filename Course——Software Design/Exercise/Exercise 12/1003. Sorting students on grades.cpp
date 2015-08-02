#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int t;
	cin >> t;
	char stu[100][10];
	int grade[100];
	char key[10];
	int a[100];
	int sub[100];
	for ( int k = 1; k <= t; k++ )
	{
		cout << "test case " << k << ":\n";
		memset(grade,0,sizeof(grade));
		memset(a,0,sizeof(a));

		int n;
		cin >> n;
		for ( int i = 0; i < n; i++ )
			for ( int j = 0; j < 10; j++ )
			{
				getchar();
				scanf("%c",&stu[i][j] );
			}
		for ( int i = 0; i < 10; i++ )
		{
			getchar();
			scanf("%c",&key[i]);
		}
		for (int i = 0; i < n; i++ )sub[i] = i;		
		for ( int i = 0; i < 10; i++ )
			for ( int j = 0; j < n; j++ )
			{
				if ( stu[j][i] == key[i] ){
				++grade[j];
				++a[j];
			}
			}
		for ( int i = 0; i < n; i++ )
			for ( int j = i+1; j < n; j++ )
			{
				if ( a[i] > a[j] )
				{
					swap(a[i],a[j]);
					swap(sub[i],sub[j]);
				}
			}
		
		for ( int i = 0; i < n; i++ )
		{
			cout << "Student " << sub[i] << ": " << grade[sub[i]] << endl; 
		}
	}
	
	return 0;
}
