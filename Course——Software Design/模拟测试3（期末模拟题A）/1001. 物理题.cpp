#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
  int n;
  cin >> n;
  while ( n-- )
  {
    int a, m;
    cin >> a >> m;
    double d = a;
    for ( int i = 0; i < m-1; i++ )
      d += 1.0*a/(1<<i);
    cout << fixed << setprecision(1);
    cout << d << ' ' << (1.0*a)/pow(2,m) << endl;


  }

  return 0;
}