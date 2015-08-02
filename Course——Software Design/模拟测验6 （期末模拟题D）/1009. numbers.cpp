#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int k[8] = {0, 0, 1, 1, 1, 3, 3, 1};

int dp( int n)
{
    if ( n < 0 )return 0;
    if ( n == 0 )return 1;
    int ret = 1;
    for ( int i = 2; i <= 7; i++ )
        ret += k[i]*dp(n-i);
    return ret;
}

int main()
{
    int n;
    while ( cin >> n && n != -1 )
    {
        int ret = 0;
        for ( int i = 2; i <= 7; i++ )
        {
            if ( i != 6 )
                ret += k[i]*dp(n-i);
            else ret += (k[i]-1)*dp(n-i);
        }
        if ( n >= 6 ) ret++;
        cout << ret << endl;
    }
    return 0;
}

