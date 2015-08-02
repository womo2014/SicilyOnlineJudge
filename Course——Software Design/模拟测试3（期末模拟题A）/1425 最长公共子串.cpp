#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str[20];
    int n;
    cin >> n;
    for ( int i = 0; i < n; i++ )
        cin >> str[i];
    int len = str[0].size();
    string t;
    // cout << endl;
    for ( int i = len; i >= 1; i-- )
    {
        int flag1 = 0;
        for ( int j = 0; i+j <= len; j++ )
        {
            t = str[0].substr(j,i);
            // cout << t << endl;
            int flag2 = 1;
            for ( int k = 1; k < n; k++ )
            {
                if ( str[k].find(t) == -1 )
                {
                    flag2 = 0;
                    break;
                }
            }
            if ( flag2 == 1 ){
                flag1 = 1;
                break;
            }
            
        }
        if ( flag1 )
        {
            cout << t << endl;
            break;
        }
    }
}
