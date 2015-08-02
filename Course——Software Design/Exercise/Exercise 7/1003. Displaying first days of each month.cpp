#include <iostream>

using namespace std;
string week( int day );
int isLeap ( int year);
int main()
{
	int year, day;
	cin >> year >> day;
	cout << "January 1, " << year << " is " << week(day) << endl;
	day = (day+31) % 7;
	
	cout << "February 1, " << year << " is " << week(day) << endl;
	if (0) day = (day+29) % 7;
	else day = (day+28) % 7;
	
	cout << "March 1, " << year << " is " << week(day) << endl;
	day = (day+31) % 7;
	
	cout << "April 1, " << year << " is " << week(day) << endl;
	day = (day+30) % 7;	
	
	cout << "May 1, " << year << " is " << week(day) << endl;
	day = (day+31) % 7;	
	
	cout << "June 1, " << year << " is " << week(day) << endl;
	day = (day+30) % 7;	
	
	cout << "July 1, " << year << " is " << week(day) << endl;
	day = (day+31) % 7;	
	
	cout << "August 1, " << year << " is " << week(day) << endl;
	day = (day+31) % 7;	

	cout << "September 1, " << year << " is " << week(day) << endl;
	day = (day+30) % 7;	

	cout << "October 1, " << year << " is " << week(day) << endl;
	day = (day+31) % 7;	

	cout << "November 1, " << year << " is " << week(day) << endl;
	day = (day+30) % 7;	

	cout << "December 1, " << year << " is " << week(day) << endl;
	return 0;
}
string week( int day )
{
	switch (day)
	{
		case 0: return "Sunday";break;
		case 1: return "Monday";break;
		case 2: return "Tuseday";break;
		case 3: return "Wednesday";break;
		case 4: return "Thursday";break;
		case 5: return "Friday";break;
		case 6: return "Saturday";break;
	}
}
int isLeap ( int year)
{
	if ( year % 4 == 0 )
		if ( year % 100 == 0 )
		{
			if ( year % 400 == 0) return 1;
	   }
		else return 1;
	return 0;
}
