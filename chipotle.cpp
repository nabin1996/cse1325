// Nabin Shrestha 

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;
class Person
{
public:
    Person() {}
    Person(string firstname, string lastname) : _firstname{ firstname }, _lastname{ lastname }{}
    string get_firstname()
    {
        return _firstname;
    }
    string get_lastname()
    {
        return _lastname;
    }
private:
    string _firstname;
    string _lastname;
};
class Delivery
{
public:
    vector<Person> allperson;
    void add_driver(int i)
    {
        cout << "Enter your full name: ";
        string firstname, lastname;
        cin >> firstname >> lastname;
        allperson.push_back(Person{ firstname, lastname });
        cout << "Newest delivery person: " << firstname << "\n" << endl;
    }
    Delivery(string filename)
    {
        Person temp;
        ifstream inputfile;
        inputfile.open(filename);
        if (!inputfile.is_open())
        {
            cout << "Error in opening file!!!\n" << endl;
            exit(0);
        }
        else
        {
            while (!inputfile.eof())
            {
                string sentence;
                getline(inputfile, sentence);
                stringstream streaming(sentence);
                getline(streaming, sentence, ' ');
                temp.get_firstname() = sentence;
                getline(streaming, sentence, ' ');
                temp.get_lastname() = sentence;
                allperson.push_back(temp);

            }
        }
        inputfile.close();
    }


};
class Order
{
public:
    string s2;
    string s3;
    string s4;
    string s5;
};

class AllOrders
{
public:
    vector<Order> rack;
    int total = 0;
    AllOrders()
    {

    }
    AllOrders(bool* b1)
    {
        total += 1;
        string ans;
        cout << "\n***Place your order***" << endl;
        Order temp;
        cout << "Burrito or Bowl?" << endl;
        cin >> ans;
        if (ans == "burrito" || ans == "Burrito")
        {
            temp.s2 = "Burrito";
            cout << "Burrito will be $6.75\n" << endl;
        }
        else if (ans == "bowl" || ans == "Bowl")
        {
            temp.s2 = "Bowl";
            cout << "Bowl will be $10\n" << endl;
        }


        cout << "-Pick: Tofu, Steak, Chicken" << endl;
        cin.ignore();
        getline(cin, ans);
        temp.s3 = ans;
        cout << "\n-Pick: Cilantro-Lime Brown, Cilantro-Lime White" << endl;
        getline(cin, ans);
        if (ans == "none")
        {
            temp.s4 = "";
        }
        else
        {
            temp.s4 = ans;
        }
        cout << "\n-Pick: Queso, Sour Cream, Fresh Tomato Salsa" << endl;
        getline(cin, ans);
        if (ans == "none")
        {
            temp.s5 = "";
        }
        else
        {
            temp.s5 = ans;
        }
        /*cout<<"Confirm order (yes or no):\n"<<
                temp.s2<<": "<<temp.s3<<", "<<
                temp.s4<<", "<<temp.s5<<endl;*/
        cout << "\nConfirm order (yes or no):\n" <<
            temp.s2 << ": " << temp.s3;
        if (temp.s4 == "")
        {

        }
        //cout<<','<<temp.s4;
        else
            cout << ", " << temp.s4;
        if (temp.s5 == "")
        {

        }
        else
        {
            cout << ", " << temp.s5 << endl;
        }
        cin >> ans;
        if (ans == "Yes" || ans == "yes")
        {
            rack.push_back(temp);
        }
        else
        {
            temp.s2 = "";
            temp.s3 = "";
            temp.s4 = "";
            temp.s5 = "";
            *b1 = false;
        }
    }
};

int main(int argc, char** argv)
{
    string s1;
    cout << "Ronnie's Delivery service..." << endl;
    Delivery pile("chipotle.txt");
    int count = 0;
    int i = 0;
    AllOrders start();
    ofstream output;
    output.open("net.txt");
    while (s1 != "3")
    {
        cout << "-----------------------------" << endl;
        cout << "Pick from the following menu: \n" <<
            "1. Customer\n" <<
            "2. Apply\n" <<
            "3. Exit" << endl;
        cin >> s1;
        if (s1 == "3")
        {
            continue;
        }
        if (s1 == "1")
        {
            bool b1 = true;
            AllOrders start(&b1);
            if (b1 == true)
            {
                cout << "\nOk, " << pile.allperson[i++].get_firstname() << " will be delivering your order. Thank you.\n" << endl;
                count += 5;
            }
        }
        else if (s1 == "2")
        {
            pile.add_driver(i);
        }
        else
        {
            cout << "invalid input!" << endl;
        }
    }
    cout << "Exiting..." << endl;
    cout << "Total made:" << count << endl;
    output.close();
}
