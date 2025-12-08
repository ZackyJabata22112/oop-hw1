#pragma once
#include <iostream>
using namespace std;

class Author
{
    private:
        //chlenove
        string name{"Unknown"};
        int birthYear{1900};

    public:
        //constructors
        Author() = default; //default
        Author(string n, int by) : name(n), birthYear(by) {} //parameterised with list

        //getters
        string getName() const
        {
            return name;
        }

        int getBirthYear() const
        {
            return birthYear;
        }

        //setters
        void setName(string n)
        {
            if (!n.empty())
            {
                name = n;
            } else
            {
                throw invalid_argument("Invalid! Name cannot be empty.");
            }
        }

        void setBirthYear (int by)
        {
            if (by >= 1850 && by <= 2025)
            {
                birthYear = by;

            }else
            {
                throw invalid_argument("Invalid! Birth year must be between 1850-2025.");
            }
        }

        //to_string method
        string to_string() const
        {
            return name + " - " + std::to_string(birthYear);
        }
}; //end Author class
