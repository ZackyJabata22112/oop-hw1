#pragma once
#include <iostream>
using namespace std;

class Loan
{
    private:
        //chlenove
        string isbn;
        string memberId;
        string startDate;
        string dueDate;
        bool returned;

    public:
        //constructor
        Loan(string i, string mId, string sD, string dD, bool r) : isbn(i), memberId(mId), startDate(sD), dueDate(dD), returned(r)
        {
            if (!(dueDate >= startDate)) {
                throw invalid_argument("Invalid! The Due Date cannot be earlier than the Start Date");
            }
        } // parameterised with list

        //getters
        string getIsbn() const
        {
            return isbn;
        }

        string getMemberId() const
        {
            return memberId;
        }

        string getStartDate() const
        {
            return startDate;
        }

        string getDueDate() const
        {
            return dueDate;
        }

        bool getReturned() const
        {
            return returned;
        }

        //setters
        void setIsbn(string i)
        {
            if (!i.empty())
            {
                isbn = i;
            } else
            {
                throw invalid_argument("Invalid! ISBN cannot be empty.");
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

        void setStartDate(string sD)
        {
            if (!sD.empty())
            {
                startDate = sD;
            } else
            {
                throw invalid_argument("Invalid! Start Date cannot be empty.");
            }
        }

        void setDueDate(string dD)
        {
            if (!dD.empty())
            {
                if (dD < startDate) {
                    throw invalid_argument("Invalid! The Due Date cannot be earlier than the Start Date");
                } else
                {
                   dueDate = dD;
                }
            } else
            {
                throw invalid_argument("Invalid! Due Date cannot be empty.");
            }
        }

        void setReturned(bool r)
        {
            returned = r;
        }

        //methods
        void markReturned() {
            returned = true;
        }

        bool isOverdue(const string& today) const
        {
            if (returned)
            {
                return false;
            } else
            {
                return dueDate < today;
            }
        }

        //to string method
        string to_string() const
        {
            return isbn + " - " + memberId + " - " + startDate + " - " + dueDate;
        }
}; // end Loan class
