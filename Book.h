#pragma once
#include <iostream>
#include "Author.h"
using namespace std;

class Book
{
    private:
        //chlenove
        string title;
        Author author;
        int year;
        double price;
        string isbn;

        //static chlenove
        static int totalBooks;

    public:
        //constructors
        Book() { ++totalBooks; }; //default
        Book(string t, Author a, int y, double p, string i) : title(t), author(a), year(y), price(p), isbn(i) { ++totalBooks; } // parameterised with list

        Book(const Book& other) : title(other.title), author(other.author), year(other.year), price(other.price), isbn(other.isbn) { ++totalBooks; } //copy constructor

        Book(Book&& other) noexcept : title(move(other.title)), author(move(other.author)), year(other.year), price(other.price), isbn(move(other.isbn)) { ++totalBooks; } //move constructor

        //operators
        Book& operator=(const Book&) = default; //copy operator
        Book& operator=(Book&&) = default; // move operator

        // destructor
        ~Book() { --totalBooks; };

        // methods

        //getters
        string getTitle() const
        {
            return title;
        }

        Author getAuthor() const
        {
            return author;
        }

        int getYear() const
        {
            return year;
        }

        double getPrice() const
        {
            return price;
        }

        string getIsbn() const
        {
            return isbn;
        }

        //setters
        void setTitle(string t)
        {
            if (!t.empty())
            {
                title = t;
            } else
            {
                throw invalid_argument("Invalid! Title cannot be empty.");
            }
        }

        void setAuthor(Author a)
        {
            if (!a.getName().empty())
            {
                author = a;
            } else
            {
                throw invalid_argument("Invalid! Author cannot be empty.");
            }
        }

        void setYear(int y)
        {
            if (y >= 1000 && y <= 2025)
            {
                year = y;
            } else
            {
                throw invalid_argument("Invalid! Year must be between 1000-2025.");
            }
        }

        void setPrice(double p)
        {
            if (p > 0)
            {
                price = p;
            } else
            {
                throw invalid_argument("Invalid! Price must be between over 0 lv.");
            }
        }

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

        //to string method
        string to_string() const
        {
            return title + " - " + author.getName() + " - " + std::to_string(year) + " - " + std::to_string(price) + " - " + isbn;
        }

        static int getTotalBooks()
        {
            return totalBooks;
        }

}; // end Book class
