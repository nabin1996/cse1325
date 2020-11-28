//Nabin Shrestha 1001746226
#include <iostream>
#include <string>
#include <vector>

class Rider
{
public:
Rider (std::string name, int height):_name{name},_height{height}{}
Rider(int height):_height{height}{}
int get_height() { return _height; }
private:
std::string _name;
int _height;
};

class Ride
{
public:
Ride(int height,std::string ridename):_height{height},_ridename{ridename}{}
void add_line(Rider riderno)
{
//int a = riderno.get_height();
if (riderno.get_height() < _height)
{
std::cout << "Sorry can't add rider-too short\n";
//return _riders.size();
}
else
{
_riders.push_back(riderno);
std::cout << "Adding rider to line\n";
//return _riders.size();
}
}
private:
std::vector<Rider> _riders;
int _height;
std::string _ridename;

};


class Amusement_park
{
public:
Amusement_park(int rides) :_noride{ rides }
{
int height;
std::string name;
std::cout << "~~~Amusement Part Info~~~\n";
for (int i = 0; i < _noride; i++)
{
std::cout << "Ride "<<i+1<<"-Enter minimum ride height and name\n";
std::cin >> height;
std::cin >> name;
_ride.push_back(Ride{ height,name });
}
}
Ride get_ride(int position)
{
return _ride.at(position-1);
}
private:
int _noride;
std::vector<Ride> _ride;
};

int main(int argc, char** argv)
{
Rider r1("Yaris", 45); //name, height in inches
Rider r2(49); //height in inches
Amusement_park a1(3); //3 is the number of rides in the amusement park
a1.get_ride(1).add_line(r1); //add a rider to the line of a ride
Amusement_park a2(2); //2 is the number of rides in the amusement park
a2.get_ride(1).add_line(r2); //add a rider to the line of a ride
return 0;
}