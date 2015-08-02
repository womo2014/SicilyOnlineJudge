#include <iostream>
#include <string>
#include <iomanip>
#include <cstdio>
using namespace std;
 
class Date {
    public:
        Date();
        Date(const Date&);
        Date(const string&);
        Date(int, int = 2, int = 29);
        void setDate(const string&);
        void printDate() const;
        int getYear() const;
        int getMonth() const;
        int getDay() const;
    private:
        bool checkFormat(const string&) const;
        bool validate();
        int year, month, day;
        bool pass;
};
 
/******** this part should be submitted ********/
#include <cstdio>
int check[13] = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
Date::Date() {
	year = 2006;
	month = 1;
	day = 1; 
	pass = true;
}
 
Date::Date(const Date& anotherDate) {
	year = anotherDate.getYear();
	month = anotherDate.getMonth();
	day = anotherDate.getDay();
	if ( validate() ) 
		pass = true;
	else pass = false;
}
 
Date::Date(const string& input) {
	setDate(input);
}
 
Date::Date(int year, int month, int day) {
	Date::year = year;
	Date::month = month;
	Date::day = day;
	if ( validate() ) 
		pass = true;
	else pass = false;
}
 
void Date::printDate() const {//print date
	if ( pass ) 
		printf("%04d-%02d-%02d\n",year,month,day);
	else cout << "Invalid Date" << endl;
}
 
int Date::getYear() const { // get data member year
	return year;
}
 
int Date::getMonth() const {// get data member month
	return month;
}
 
int Date::getDay() const {// get data member day
	return day;
}
 
void Date::setDate(const string& input) {
	if ( !checkFormat(input) ) //invalid format, do nothing
		return;
	year = month = day = 0;//set date
	for ( int i = 0; i != 4; ++i ) 
		year = year*10 + input[i]-'0';
	for ( int i = 5; i != 7; ++i ) 
		month = month*10 + input[i]-'0';
	for ( int i = 8; i != 10; ++i ) 
		day = day*10 + input[i]-'0';
	validate(); // check date
}
 
bool Date::checkFormat(const string& input) const {
	if ( input.size() != 10 ) return false;
	for ( int i = 0; i != 10; ++i ) {
		if ( i == 4 || i == 7 ) {
			if ( input[i] != ':' ) return false;
		}
		else if ( input[i] < '0' || input[i] > '9' )
			return false;
	}
	return true;
}
 
bool Date::validate() {
	if ( year < 0 || month <= 0 || month >= 13 ||
		 day <= 0 || day >= 32 ) return pass = false;
	if ( month == 2 ) {
		if ( year % 4 != 0 || year % 100 == 0 && year % 400 != 0 ) {
			if ( day > 28 ) return pass = false;
		}
		else if ( day > 29 ) return pass = false;
	}
	else if ( day > check[month] ) return pass = false; 
	return pass = true;
}
/******** this part should be submitted ********/
 
int main() {
	int T;
	int flag;
	Date* myDate;
	
	string dateString;
	int year, month, day;
	
	cin >> T;
	while (T--) {
		cin >> flag;
		if (flag == 1) {
			cin >> dateString;
			myDate = new Date(dateString);			
		}
		else if (flag == 2) {
			cin >> year;
			myDate = new Date(year);
		}
		else if (flag == 3) {
			cin >> year >> month;
			myDate = new Date(year, month);
		}
		else if (flag == 4) {
			cin >> year >> month >> day;
			myDate = new Date(year, month, day);
		}
 
		myDate->printDate();
	}
	
	return 0;
}