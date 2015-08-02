//1007. Calf Flac
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string a, b;
	vector<string> str;
	while ( getline(cin, a) )
	{
		str.push_back(a);
		b += a;
	}
    
	vector<int> rcd;    
	int i(0);   
    while ( i < b.size() )
    {
    	if ( isalpha(b[i]) )
    	{
    		rcd.push_back(i);
    		b[i] = tolower(b[i]);
    	}
    	i++;
    }
    
	int size = *(rcd.end()-1);
    i = rcd[0];
    int j = i, x = i, y = i, lenth(1);
    int cnti(0), cnt(0), copy_cnt(0);
    string c, d;
    c = b[i];
    d = c;
    while ( rcd.size()-cnti > lenth )
    {
		cnt = copy_cnt;
		copy_cnt++;
		j = rcd[cnt];
		while ( j < size )
		{
			j = rcd[++cnt];
			c = c + b[j];
			d = b[j] + d;
			cout << "@" << c << endl;
			if ( c == d )
			{
				x = i;
				y = j;
				lenth = c.size();
				copy_cnt = cnt+1;
			}
		}
		if ( c.size() == lenth )
		{
			break;
		}
		
		c = c.substr(1,lenth);
		d = d.substr(d.size()-lenth-1,lenth);
		cout << "#" << c << endl;

		if ( i < size ) 
			i = rcd[++cnti];
		cout << b[i] << endl;
    }
	
	cout << lenth << endl;
	i = 0;
	while ( x+1 > str[i].size() )
	{
		x -= str[i].size();
		y -= str[i].size();
		i++;
	}
	if ( y+1 <= str[i].size() )
	{
		cout << str[i].substr(x, y-x+1) << endl;
	}
	else {
		cout << str[i].substr(x) << endl;
		y -= str[i].size();
		i++;
		while ( y+1 > str[i].size() )
		{
			cout << str[i] << endl;
			y -= str[i].size();
			i++;
		}
		cout << str[i].substr(0, y+1) <<endl;
	}
	return 0;
}

