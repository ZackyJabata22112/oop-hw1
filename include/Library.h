#pragma once
#include <iostream>
#include <vector>
#include "Book.h"
#include "Member.h"
#include "Loan.h"
using namespace std;

class Library
{
    private:
        vector<Book> books;
        vector<Member> members;
        vector<Loan> loans;

    public:
        //methods
        void addBook(const Book& b)
        {
            books.push_back(b);
        }

        void addMember(const Member& m)
        {
            members.push_back(m);
        }

        bool hasBook(const string& isbn) const
        {
            for (const Book& b : books)
            {
                if (b.getIsbn() == isbn)
                    return true;
            }

            return false;
        }

        bool isBookAvailable(const string& isbn) const
        {
            if (!hasBook(isbn))
            {
                return false;
            }

            for (const Loan& l : loans)
            {
                if (l.getIsbn() == isbn && !l.getReturned())
                {
                    return false;
                }
            }

            return true;
        }

        bool loanBook(const string& isbn, const string& memberId, const string& start, const string& due)
        {
            if (!isBookAvailable(isbn))
            {
                return false;
            }

            for (const Member& m : members)
            {
                if (m.getMemberId() == memberId)
                {
                    loans.emplace_back(isbn, memberId, start, due, false);
                    return true;
                }
            }

            return false;
        }

        bool returnBook(const string& isbn, const string& memberId)
        {
            for (Loan& l : loans)
            {
                if (l.getIsbn() == isbn && l.getMemberId() == memberId && !l.getReturned())
                {
                    l.markReturned();
                    return true;
                }
            }

            return false;
        }

        vector<Book> findByAuthor(const string& authorName) const
        {
            vector<Book> result;

            for (const Book& b : books)
            {
                if (b.getAuthor().getName() == authorName)
                {
                    result.push_back(b);
                }
            }

            return result;
        }

        string to_string() const
        {
            int activeLoans = 0;

            for (const Loan& l : loans)
            {
                if (!l.getReturned())
                {
                    activeLoans++;
                }
            }

            return "Library: \nBooks: " + std::to_string(books.size()) + "\nMembers: " + std::to_string(members.size()) +"\nActive Loans: " + std::to_string(activeLoans) + "\n";
        }
}; // end Library class
