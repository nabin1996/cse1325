//Nabin Shrestha 1001746226
#include <iostream>
#include <vector>
#include <string>
class Currrency
{
public:
	Currrency(std::string name, double rate) :_name{ name }, _rate{ rate }{}
	double get_money(double money)
	{
		if (_rate > 1)
		{
			return money / _rate;
		}
		else
		{
			return money * _rate;
		}
	}
	std::string get_name()
	{
		return _name;
	}
private:
	std::string _name;
	double _rate;

};
class Office
{
public:
	Office(std::string name, std::string manager) :_name{ name }, _manager{ manager }{}
	std::string get_manager()
	{
		return _manager;
	}
	std::string get_name()
	{
		return _name;
	}
private:
	std::string _name;
	std::string _manager;
};
int main()
{
	std::string office_name, middle, manager_name;
	std::vector<Office> _office;
	std::vector<Currrency> curriencies;
	curriencies.push_back(Currrency{ "yen", 106.94 });
	for (int i = 0; i < 2; i++)
	{
		std::cout << "Enter name of exchange office and manager: ";
		std::cin >> office_name >> middle;
		office_name = office_name + " " + middle;
		std::cin >> manager_name;
		_office.push_back(Office{ office_name,manager_name });
		//std::cout << office_name;
	}
	std::string currency_name;
	int amount;
	while (middle != "exit")
	{
		std::cout << "Hello Traveller! Where are you in the airport?";
		std::cin >> middle;
		std::cout << middle;
		if (middle == "North" || middle == "East" || middle == "e" || middle == "n" || middle == "north" || middle == "east")
		{
			for (auto v : _office)
				if (v.get_name() == "ABC Conversions")
				{
					std::cout << "Welcome to " << v.get_name() << " .Please contact the manager " << v.get_manager() <<
						"if you have any complaints.\n What currency are you converting to dollar and how much?";
					std::cin >> amount;
					std::cin.ignore(32767, '\n');
					std::cin >> currency_name;
					//std::cin >> amount;
					for (auto v : curriencies)
					{
						if (v.get_name() == currency_name)
							std::cout << "Here you go: $" << v.get_money(amount) << std::endl;
						else
							std::cout << "We don't convert the " << currency_name << " here.Sorry \n";
					}

				}

		}
		if  (middle == "South" || middle == "West" || middle == "w" || middle == "s" || middle == "west" || middle == "south" )
		{
				for (auto v : _office)
					if (v.get_name() == "DEF Conversions")
					{
						std::cout << "Welcome to " << v.get_name() << " .Please contact the manager " << v.get_manager() <<
							"if you have any complaints.\n What currency are you converting to dollar and how much?";
						std::cin >> amount;
						std::cin.ignore(32767, '\n');
						std::cin >> currency_name;
						//std::cin >> amount;
						for (auto v : curriencies)
						{
							if (v.get_name() == currency_name)
								std::cout << "Here you go: $" << v.get_money(amount) << std::endl;
							else
								std::cout << "We don't convert the " << currency_name << " here.Sorry \n";
						}

					}

			}

	}


	return 0;
}