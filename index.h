#pragma once

#include <string>

using namespace std;

class Person
{
private:
    string firstName = "";
    string middleName = "";
    string lastName = "";
    int birthYear = 0;
public:
    Person(string fn, string mn, string ln, int by)
    {
        this->firstName = fn;
        this->middleName = mn;
        this->lastName = ln;
        this->birthYear = by;
    }
    ~Person() = default;
    string GetFirstName()
    {
        return this->firstName;
    }
    string GetMiddleName()
    {
        return this->middleName;
    }
    string GetLastName()
    {
        return this->lastName;
    }
    string GetFullName()
    {
        return this->firstName + this->middleName + this->lastName;
    }
    string GetFIO()
    {
        return this->middleName[0] + this->firstName[0] + this->lastName[0];
    }
    int GetBirthYear()
    {
        return this->birthYear;
    }
    int GetAge(int year)
    {
        return year - this->birthYear;
    }
};