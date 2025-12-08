#pragma once
#include <iostream>
using namespace std;

class Member
{
    private:
        //chlenove
        string name;
        string memberId;
        int yearJoined;

    public:
        //constructors
        Member() = default; // default
        Member(string n, string mId, int yJ) : name(n), memberId(mId), yearJoined(yJ) {} // parameterised with list


        //getters
        string getName() const
        {
            return name;
        }

        string getMemberId() const
        {
            return memberId;
        }

        int getYearJoined() const
        {
            return yearJoined;
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

        void setMemberId(string mId)
        {
            if (!mId.empty())
            {
                memberId = mId;
            } else
            {
                throw invalid_argument("Invalid! Member Id cannot be empty.");
            }
        }

        void setYearJoined(int yJ)
        {
            if(yJ >= 1875 && yJ <= 2025){
                yearJoined = yJ;

            } else
            {
                throw invalid_argument("Invalid! Year joined must be between 1875-2025.");
            }
        }

        //methods
        string to_string() const
        {
            return name + " - " + memberId + " - " + std::to_string(yearJoined);
        }
}; // end Member class
