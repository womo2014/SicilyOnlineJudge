#include <cstring>
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
    char str[100+5];
    gets(str);
    int len = strlen(str);
    string word[100];
    int cnt = 1;
    for ( int i = 0; i < len; i++ )
    {
        if ( isalpha(str[i]) )
        {
            word[cnt].push_back(str[i]);
        }
        else if ( i != 0 && isalpha(str[i-1]) )cnt++;
    }
    for ( int i = 0; i < cnt; i++ )
    {
        int j;
        for ( j = i; j <= i+cnt-1; j++ )
            cout << word[j%cnt+1] << " ";
        
        cout  << endl;
    }
    
} 
