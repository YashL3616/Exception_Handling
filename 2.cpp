//inheritance
#include <iostream>

using namespace std;

class BaseException : public exception {
public:
    BaseException(const string& message) : message(message) {}

    virtual const string& what() const override {
        return message;
    }

private:
    string message;
};

class DerivedException : public BaseException {
public:
    DerivedException(const string& message) : BaseException(message) {}
};

class Person {
public:
    void validateAge(int age) {
        if (age < 0 || age > 120) {
            throw DerivedException("Invalid age: " + to_string(age));
        }
    }
};

class Employee : public Person {
public:
    void validateEmployee(int age, const string& title) {
        Person::validateAge(age);
        if (title.empty()) {
            throw BaseException("Employee must have a title");
        }
    }
};

int main() {
    try {
        Employee employee;
        employee.validateEmployee(-1, "");
    } catch (const BaseException& e) {
        cout << "Base exception: " << e.what() << endl;
    } catch (const DerivedException& e) {
        cout << "Derived exception: " << e.what() << endl;
    } catch (const exception& e) {
        cout << "Unexpected exception: " << e.what() << endl;
    }

    return 0;
}

