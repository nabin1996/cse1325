//Nabin Shrestha 1001746226
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int shapes(string shape)
{
	int i =0;
	do
	{
		cout << "\n" << i+1 << " shape: ";
		cin >> shape;
		i++;
		
		if (shape == "triangle")
		{
			cout << "area = (base *height) /2\n"<<endl;
		}
		else if (shape == "square")
		{
			cout << "area = length * length\n" << endl;
			cout << "perimeter = 4 * length\n" << endl;
		}
		else if (shape == "rectangle")
		{
			cout << "area = length * breadth \n" << endl;
			cout << "perimeter = 2(length * breadth) \n" << endl;
		}
		else if(shape != "exit")
			cout << "Sorry,	information	for	this	shape	is	not	available.\n" << endl;
	}while(shape != "exit");
	return i-1;
}
int main ()
{
	int num;
	string name;
	cout << "\n**********\n shapes! \n*********\n" <<endl;
	num = shapes(name);
	cout << num << " shapes entered \n Exiting..." << endl;
}




			