#include <iostream>

using namespace std;

int main()
{
	int year, month;
	cin >> year >> month;
	switch (month) {
		case 1:cout << "January";break;
		case 2:cout << "February";break;
		case 3:cout << "March";break;
		case 4:cout << "April";break;
		case 5:cout << "May";break;
		case 6:cout << "June";break;
		case 7:cout << "July";break;
		case 8:cout << "August";break;
		case 9:cout << "September";break;
		case 10:cout << "October";break;
		case 11:cout << "November";break;
		case 12:cout << "December";break;
	}
	
	int days = 31;
	if ( month == 2 )
	{
		if ( year % 4 == 0 && ( year % 400 == 0 || year % 100 != 0 ) )
				days = 29;
		else days = 28;
	}
	else if ( month == 4 || month == 6 || month == 9 || month == 11 )
		days = 30;
	cout << ' ' << year << " has " << days << " days" << endl;
	return 0;
}
