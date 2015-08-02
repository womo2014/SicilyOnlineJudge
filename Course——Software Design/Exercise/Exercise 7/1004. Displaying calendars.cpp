#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int isLeap ( int year);
string month_ch(int month);
int monthday(int month, int year);

int main()
{
   int year, day, month;
   cin >> year >> day >> month;
   cout << month_ch(month) << ' ' << year << endl;
   cout << setw(8) << "Sun" << setw(8) << "Mon" 
        << setw(8) << "Tue"<< setw(8) << "Wed"
        << setw(8) << "Thu" << setw(8) << "Fri" 
        << setw(8) << "Sat" << endl;
   int month_days = monthday(month, year);
   
   for ( int k = 1; k < month; k++)
   {
   	day = (day+monthday(k, year) ) % 7;
   }
   int n = day;
	
	for (int i = 1; i <= month_days;n = 0)
   {
      for ( int j = 1; j <= 7 && i <= month_days; j++)
      {
         if (j <= n)
            cout << "        ";
         else 
            cout << setw(8) << i++;
      }
      cout << endl;  
   }
   
   return 0;   
}
int isLeap ( int year)
{
    if ( year % 4 == 0 )
    {    
       if ( year % 100 == 0 )
       {
          if ( year % 400 == 0) return 1;
       }
       else return 1;
    }
    return 0;
}
string month_ch(int month)
{
   switch (month)
   {
      case 1: return "January"; break;
      case 2: return "February"; break;     
      case 3: return "March"; break;       
      case 4: return "April"; break;       
      case 5: return "May"; break;       
      case 6: return "June"; break;       
      case 7: return "July"; break;       
      case 8: return "August"; break;       
      case 9: return "September"; break;       
      case 10: return "October"; break;       
      case 11: return "November"; break;
      case 12: return "December"; break;              
   }
}
int monthday(int month, int year)
{
   int days = 31;
   if (month == 2)
   {
      if ( isLeap(year) )
         days = 29;
      else           
         days = 28;                
   }
   else if (month == 4 || month == 6 ||
            month == 9 || month == 11 )
      days = 30;
   
   return days; 
}                                 
