#include <iostream>
using namespace std;

class Exp_handling {
protected:
    int age;
    long double income;
    string city;

public:
    void getdata() {
        cout << "Enter the age :" << endl;
        cin >> age;
        cout << "Enter the income :" << endl;
        cin >> income;
        cout << "Enter the city :" << endl;
        cin >> city;
    }

    void check() {
        try {
            if (age < 18 || age > 55) {
                throw "Age should be between 18-55";
            }
        } catch (const char *res) {
            cerr << res << endl;
        }

        try {
            if (income < 50000 || income > 100000) {
                throw "Income should be between 50,000 and 1,00,000";
            }
        } catch (const char *res) {
            cerr << res << endl;
        }

        try {
            if (!(city == "Pune" || city == "pune" || city == "Mumbai" || city == "mumbai" || city == "chennai" ||
                  city == "Chennai" || city == "delhi" || city == "Delhi")) {
                throw "City should be delhi/pune/mumbai/chennai";
            }
        } catch (const char *res) {
            cerr << res << endl;
        }
    }
};

class SpecialExp_handling : public Exp_handling {
public:
    void check() {
        // Override the check method to add additional validation rules
        Exp_handling::check();  // Call the base class check method

        try {
            // Add additional validation rules specific to the derived class
            if (income < 70000) {
                throw "Income should be at least 70,000 for the special case";
            }
        } catch (const char *res) {
            cerr << res << endl;
        }
    }
};

int main() {
    // Use the derived class for special cases
    SpecialExp_handling specialCase;
    specialCase.getdata();
    specialCase.check();

    // Use the base class for general cases
    Exp_handling generalCase;
    generalCase.getdata();
    generalCase.check();

    return 0;
}
