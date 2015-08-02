//1007. Calf Flac
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string a;
	vector<string> str;
	while ( getline(cin, a) )
	{
		str.push_back(a);
	}
	string b;
	for ( vector<string>::iterator it = str.begin();
		 				   it != str.end(); ++it )
	{
		b += *it;
	}
    
	int i(0), j(0);
    int x(0), y(0), lenth(1);
	string c;
	c = b[0];
	string d = c;
    int copy = 0;
    int jd = 0;
    while ( i < b.size() )
    {
    	j = copy;
		if ( jd )
    	{
    		while ( ++j < b.size() && !isalpha(b[j]) );
    		copy = j;
    		c = c + (char)tolower(b[j]);
    		d = (char)tolower(b[j]) + d;
    	}
    	jd = 1;
		while ( j < b.size() )
		{
			while ( ++j < b.size() && !isalpha(b[j]) );
			if ( j < b.size() )
			{
				c = c + (char)tolower(b[j]);
    			d = (char)tolower(b[j]) + d;
    			if ( c == d )
				{
					x = i;
    				y = j;
    				lenth = c.size();
    				copy = j;
    			}
			}
		}
		c.erase(lenth);
		c.erase(0, 1);
		d.erase(0, d.size() - lenth);
		d.erase(d.size() - 1);		
		while ( ++i < b.size() && !isalpha(b[i]) );
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

