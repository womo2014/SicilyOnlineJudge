//1006.最长回文子串 
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int ishw ( int i, int j, string b );

int main()
{
    string a;
    
    while ( cin >> a )
    {
        int i, j;
        int cnt = 0;
        int max = 0;
        int d = 1;
        for ( i = 0; i < a.size()-1; i++ )
        {
            for ( j = i+d; j < a.size(); j++ )
            {
                int x = ishw(i, j, a);
                if ( max < x )
                {
                    max = x;
                    d = max;
                }
            }
        }
        if ( max == 0 )
            max = 1;
        cout << max << endl;
    }   
    return 0;
}

int ishw ( int i, int j, string b )
{
    int ret = 0;
    string c;
    int k;
    for ( k = j ; k >= i; k-- )
    {
        c += b[k];
    }
    string d;
    for ( k = c.size()-1; k >= 0; k-- )
    {
    	d += c[k];
    }
    if ( c == b.substr(i, c.size()) )
    {
        ret = c.size(); 
    }
    return ret;
}      
