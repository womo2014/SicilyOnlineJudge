#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void swap( string::iterator a, string::iterator b );
int partition( string a, int low, int high );
void quicksort(string a, int low, int high);

int main()
{
	string str;
	while ( cin >> str )
	{
		sort(str.begin(), str.end());
		for ( int i = str.size()-1; i >= 0; i-- )
		{
			cout << str[i];
		}
		cout << endl;
	}
	
	return 0;
} 
void swap( string::iterator a, string::iterator b )
{
	char temp = *a;
	*a = *b;
	*b = temp;
}
int partition( string a, int low, int high )
{
	char privotkey = a[low];
	while ( low < high) {
		while ( low < high && a[high] <= privotkey ) high--;
		swap(a.begin()+low, a.begin()+high);
		while ( low < high && a[high] >= privotkey ) low++;
		swap(a.begin()+low, a.begin()+high);
	}
	return low;
}
void quicksort(string a, int low, int high)
{
	if ( low < high )	
	{
		int privotLoc = partition(a, low, high);
		quicksort(a, privotLoc+1,high);
		quicksort(a, low, privotLoc-1);
	}
}
