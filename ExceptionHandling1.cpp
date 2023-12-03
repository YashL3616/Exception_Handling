#include<iostream>
using namespace std;

class Exp_handling
{
private:
    int age, vehicle;
    long double income;
    string city;

public:
    void getdata()
    {
        cout << "Enter the age :" << endl;
        cin >> age;
        cout << "Enter total no. of vehicle wheels :" << endl;
        cin >> vehicle;
        cout << "Enter the income :" << endl;
        cin >> income;
        cout << "Enter the city :" << endl;
        cin >> city;
    }

    void check()
    {
        try
        {
            if (age < 18 || age > 55)
            {
                throw "Age should be between 18-55";
            }
        }
        catch (const char *res)
        {
            cerr << res << endl;
        }

        try
        {
            if (income < 50000 || income > 100000)
            {
                throw "Income should be between 50,000 and 1,00,000";
            }
        }
        catch (const char *res)
        {
            cerr << res << endl;
        }

        try
        {
            if (!(city == "Pune" || city == "pune" || city == "Mumbai" || city == "mumbai" || city == "chennai" ||
                  city == "Chennai" || city == "delhi" || city == "Delhi"))
            {
                throw "City should be delhi/pune/mumbai/chennai";
            }
        }
        catch (const char *res)
        {
            cerr << res << endl;
        }

        try
        {
            if (vehicle != 4)
            {
                throw "User must have 4 wheeler";
            }
        }
        catch (const char *res)
        {
            cerr << res << endl;
        }
    }
};

int main()
{
    Exp_handling a;
    a.getdata();
    a.check();
    return 0;
}
