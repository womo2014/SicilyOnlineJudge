#include <iostream>
#include <cstdio>

using namespace std;
void mult(char a[],char b[],char s[])
      {
          int i,j,k=0,alen,blen,sum=0,res[65][65]={0},flag=0;
          char result[65];
          ale
     n=strlen(a);blen=strlen(b); 
          for (i=0;i<alen;i++)
          for (j=0;j<blen;j++) res[i][j]=(a[i]-'0')*(b[j]-'0');
          for (i=alen-1;i>=0;i--)
              {
                  for (j=blen-1;j>=0;j--) sum=sum+res[i+blen-j-1][j];
                  result[k]=sum%10;
                  k=k+1;
                  sum=sum/10;
              }
          for (i=blen-2;i>=0;i--)
              {
                  for (j=0;j<=i;j++) sum=sum+res[i-j][j];
                  result[k]=sum%10;
                  k=k+1;
                  sum=sum/10;
              }
          if (sum!=0) {result[k]=sum;k=k+1;}
          for (i=0;i<k;i++) result[i]+='0';
          for (i=k-1;i>=0;i--) s[i]=result[k-1-i];
          s[k]='\0';
          while(1)
              {
              if (strlen(s)!=strlen(a)&&s[0]=='0') 
                  strcpy(s,s+1);
              else
                  break;
              }
      }
 
int a[100000+1];
int b[100000+1];
int c[100000+1];
int flag[100000+1];
int main()
{
	int n;
	cin >> n;
	for ( int i = 1; i <= n; i++ )
	{
		scanf("%d",&a[i]);
		int flag1 = 0;
		b[i] = c[i] = a[i];
		for ( int j = i-1; j >= 1; j-- )
		{
			if ( a[j] % a[i] == 0 && flag1 != 1) { b[i] = a[j];flag1 = 1; }
			if ( a[i] % a[j] == 0 && flag[j] != 1) { c[j] = a[i]; flag[j] = 1; }
		}
	}
	char ret[100] = "0";
	for ( int i = 1; i <= n; i++ )
	{
		char tb[10], tc[10];
		sprintf(tb,"%d",b[i]);
		sprintf(tc,"%d",c[i]);
		ret += b[i]*c[i];
	｝	
	cout << ret << endl;

	return 0;
}