
// Nabin Shrestha

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

class Person
{
public :
    Person() {}
    Person(string name, string size) : _name{ name }, _size{ size } {}
    string get_size()
    {
        return _size;
    }
    string get_name()
    {
        return _name;
    }
private:
    string _name;
    string _size;

};
class Chili_batch :protected Person
{
    vector<Person> order;
 public:
    //Chili_batch() {}
    vector<Person> get_vector()
    {
        return order;
    }
    Person from_vector(int i)
    {
        return order[i];
    }
    Chili_batch(string file)
    {
        ifstream input{ file };
        //input.open(file);
        if (!input.is_open())
        {
            cout << "Error in opening file!!!\n" << endl;
            exit(0);
        }
        else
        {
            while (!input.eof())
            {
                string sentence;
                string name;
                string size;
                getline(input, sentence);
                stringstream streaming(sentence);
                getline(streaming, sentence, ',');
                name = sentence;
                getline(streaming, sentence, ',');
                size = sentence;
                order.push_back(Person{ name, size });
            }
            input.close();
        }

        cout << "Checking today's customers.....done!" << endl;
    }
    void looping_fun()
    {
        int i = 0;
        int chili = 0;

        string s1 = "yes";
        while (s1 == "yes")
        {
            cout << "\nHow many batches of your famous chili are you making today?  ";
            cin >> chili;
            chili *= 6;
            cout << "\nStarting order...." << endl;
            string s2;

            while ((signed)(get_vector().size()) != i)
            {
                cout << "\n--Customer " << i + 1 << ": " << from_vector(i).get_name() << "'s order is " << from_vector(i).get_size() << "." << endl;

                if (from_vector(i).get_size() == "jumbo")
                {
                    chili -= 4;
                }
                else if (from_vector(i).get_size() == "Grande")
                {
                    chili -= 3;
                }
                else if (from_vector(i).get_size() == "Tall")
                {
                    chili -= 2;
                }
                else if (from_vector(i).get_size() == "Short")
                {
                    chili -= 1;
                }
                if (chili == 0)
                {
                    break;
                }
                else if (chili < 2)
                {
                    cout << "Order served. Not much chili left!\n\n" << endl;
                }
                else
                {
                    cout << "Order served. Still got lots of chili!\n\n" << endl;
                }

                cout << "Continue with order or take a break?" << endl;
                cin >> s2;
                if (s2 == "continue")
                {

                }
                else if (s2 == "break")
                {
                    cout << "\nOk. Press enter to continue when you are finished with your break.";
                    cin.ignore();
                    getline(cin, s2);
                }
                i++;
            }
            cout << "Sorry, not enough chili. Would you like to make another batch or quit?" << endl;
            cin >> s1;
        }
    }
};
int main(int argc, char** argv)
{
    cout << "Welcome Louise" << endl;
    Chili_batch Worker("chili.txt");

    Worker.looping_fun();
    return 0;
}

