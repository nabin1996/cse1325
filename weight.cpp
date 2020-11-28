//Nabin Shrestha 1001746226
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void changeunit(string name, double weight, string unit)
{
	string input;
	string unit1("pounds");
	string unit2("kilos");
	double change;
	
	while(input != "exit")
	{
		cout << "Please	enter	your	name	and	weight.	" << endl;
		getline(cin, input);
		if(input != "exit")
		{
			stringstream ss(input);
			ss >> name >> weight >> unit;
			
			if (unit.compare(unit1)==0)
			{
				change = weight/2.21;
				cout << "Hi " << name << "- you weight " << change << " kilos \n" << endl;
			}
			else if (unit.compare(unit2) == 0)
			{
				change = weight * 2.21;
				cout << "Hi " << name << "- you weight " << change << " pounds \n" << endl;
			}
			else if(unit.empty())
			{
				cout << "Not	enough	info	to	convert.\n";
			}
			unit.clear();
		}
		else if(input.compare("exit")==0)
			cout << "\nExiting..." << endl;
	}
}
int main ()
{
	string name;
	string convert;
	double weight;
	changeunit(name, weight, convert);
}

