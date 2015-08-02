#include <iostream>
#include <map>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	map<string,string> mymap;
	mymap["Alabama"] = "Montgomery";
	mymap["Alaska"] = "Juneau";
	mymap["Arizona"] = "Phoenix";
	mymap["Arkansas"] = "Little Rock";
	mymap["California"] = "Sacramento";
	mymap["Colorado"] = "Denver";
	mymap["Connecticut"] = "Hartford";
	mymap["Delaware"] = "Dover";
	mymap["Florida"] = "Tallahassee";
	mymap["Georgia"] = "Atlanta";
	mymap["Hawaii"] = "Honolulu";
	mymap["Idaho"] = "Boise";
	mymap["Illinois"] = "Springfield";
	mymap["Maryland"] = "Annapolis";
	mymap["Minnesota"] = "Saint Paul";
	mymap["Iowa"] = "Des Moines";
	mymap["Maine"] = "Augusta";
	mymap["Kentucky"] = "Frankfort";
	mymap["Indiana"] = "Indianapolis";
	mymap["Kansas"] = "Topeka";
	mymap["Louisiana"] = "Baton Rouge";
	mymap["Oregon"] = "Salem";
	mymap["Oklahoma"] = "Oklahoma City";
	mymap["Ohio"] = "Columbus";
	mymap["North Dakota"] = "Bismark";
	mymap["New York"] = "Albany";
	mymap["New Mexico"] = "Santa Fe";
	mymap["New Jersey"] = "Trenton";
	mymap["New Hampshire"] = "Concord";
	mymap["Nevada"] = "Carson City";
	mymap["Nebraska"] = "Lincoln";
	mymap["Montana"] = "Helena";
	mymap["Missouri"] = "Jefferson City";
	mymap["Mississippi"] = "Jackson";
	mymap["Massachusettes"] = "Boston";
	mymap["Michigan"] = "Lansing";
	mymap["Pennslyvania"] = "Harrisburg";
	mymap["Rhode Island"] = "Providence";
	mymap["South Carolina"] = "Columbia";
	mymap["South Dakota"] = "Pierre";
	mymap["Tennessee"] = "Nashville";
	mymap["Texas"] = "Austin";
	mymap["Utah"] = "Salt Lake City";
	mymap["Vermont"] = "Montpelier";
	mymap["Virginia"] = "Richmond";
	mymap["Washington"] = "Olympia";
	mymap["West Virginia"] = "Charleston";
	mymap["Wisconsin"] = "Madison";
	mymap["Wyoming"] = "Cheyenne";
	
	int n;
	cin >> n;
	string a,b;
	getchar();
	while ( n-- )
	{
		
		getline(cin, a);
		
		getline(cin, b);
		
		if ( mymap[a] == b ) cout << "Your anwswer is correct" << endl;
		else cout << "The capital of " << a << " is " << mymap[a] << endl;
		
	} 
	return 0;
} 
