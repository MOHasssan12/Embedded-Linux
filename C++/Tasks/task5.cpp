#include<iostream>

#include<cmath>

using namespace std;


struct Name {
    string firstName;
    string middleName;
    string lastName;
};

struct DateOfBirth {
    int day;
    int month;
    int year;
};

struct Address {
    string street;
    string city;
    string country;
};

struct Contacts {
    string telephoneNumber;
    string mobileNumber;
    string emailAddress;
};

struct Salary {
    double basic;
    double additional;
    double reductions;
    double taxes;
};

struct Employee {
    Name name;
    DateOfBirth dob;
    Address address;
    Contacts contacts;
    string job;
    Salary salary;
};





int main()
{
Employee emp;

    return 0 ;
}