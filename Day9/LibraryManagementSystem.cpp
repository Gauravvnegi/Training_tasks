/*
Day-4 OOPS
A Library Management System is a software built to handle the primary housekeeping functions of a library. Libraries rely
on library management systems to manage asset collections as well as relationships with their members. Library management systems
help libraries keep track of the books and their checkouts, as well as members’ subscriptions and profiles.
Library management systems also involve maintaining the database for entering new books and recording books that have been borrowed
with their respective due dates.
System Requirements
Always clarify requirements at the beginning of the interview. Be sure to ask questions to find the exact scope of the system that
the interviewer has in mind.
We will focus on the following set of requirements while designing the Library Management System:
Any library member should be able to search books by their title, author, subject category as well by the publication date.
Each book will have a unique identification number and other details including a rack number which will help to physically locate
 the book.
There could be more than one copy of a book, and library members should be able to check-out and reserve any copy. We will call
each copy of a book, a book item.
The system should be able to retrieve information like who took a particular book or what are the books checked-out by a specific
 library member.
There should be a maximum limit (5) on how many books a member can check-out.
There should be a maximum limit (10) on how many days a member can keep a book.
The system should be able to collect fines for books returned after the due date.
Members should be able to reserve books that are not currently available.
The system should be able to send notifications whenever the reserved books become available, as well as when the book is not
 returned within the due date.
Each book and member card will have a unique barcode. The system will be able to read barcodes from books and members’ library cards.
Use case diagram
We have three main actors in our system:
Librarian: Mainly responsible for adding and modifying books, book items, and users. The Librarian can also issue, reserve,
 and return book items.
Member: All members can search the catalog, as well as check-out, reserve, renew, and return a book.
System: Mainly responsible for sending notifications for overdue books, canceled reservations, etc.
Here are the top use cases of the Library Management System:
Add/Remove/Edit book: To add, remove or modify a book or book item.
Search catalog: To search books by title, author, subject or publication date.
Register new account/cancel membership: To add a new member or cancel the membership of an existing member.
Check-out book: To borrow a book from the library.
Reserve book: To reserve a book which is not currently available.
Renew a book: To reborrow an already checked-out book.
Return a book: To return a book to the library which was issued to a member.
*/
#include <bits/stdc++.h>
using namespace std;
class User
{
private:
    int userID;
    string requestBookName;

public:
    int setUserID(int userID)
    {
        this->userID = userID;
    }
    string setUserRequestBook(string requestBookName)
    {
        this->requestBookName = requestBookName;
    }
    int getUserID()
    {
        return userID;
    }
    string getUserRequestBook()
    {
        return requestBookName;
    }
};

class Librarian
{
private:
    User *userDetails;
    int librarianID;
    string librarianPass;
    int userID;
    string userRqBook;

public:
    Librarian(int librarianID, string librarianPass)
    {
        this->librarianID = librarianID;
        this->librarianPass = librarianPass;
    }
    bool getLibrarianID()
    {
        return librarianID;
    }
    void checKUserDetails(User *userDetails)
    {
        this->userRqBook = userDetails->getUserID();
        this->userRqBook = userDetails->getUserRequestBook();
    }
};
class AccountDetail
{
private:
    // map to store user account detail
    int userID;

public:
    bool userAccountDetail(int userID)
    {
        return true;
    }
};
class MiddleWare
{
public:
    bool checkValidLibrain()
    {
        return true;
    }
    bool checkValidUser()
    {
        return true;
    }
};
class clearDue
{
private:
    int Subscription;

public:
    bool ifAnyDue()
    {
        return true;
    }
};
class Subscription
{
    int addUserSubscription;

public:
    void setUserSubscription(int addUserSubscription)
    {
        this->addUserSubscription = addUserSubscription;
    }
    int getUserSubscription()
    {
        return addUserSubscription;
    }
};
class Payment
{
private:
    int totalPayment;

public:
    void ChooseOption(int option)
    {
        switch (option)
        {
        case 1:

            cout << "Check Money" << endl;

            break;

        case 2:

            cout << "Withdraw Money" << endl;

            break;
        }
    }
};

class CreateNewAccount
{
private:
    int userId;
    string password;
    AccountDetail *accountdetails;

public:
    bool getNewUserDetail()
    {
        return true;
    }
};
// Authenticator Databases

class LMSAuthentication
{
private:
    UserDatabase *userdatabase;
    unordered_map<int, string> LibrarianDeatils = {{1, "Librarian1"}, {2, "Librarian2"}, {3, "Librarian"}};
    unordered_map<int, string> userDetails = {{1, "User1"}, {2, "User2"}, {3, "User3"}};

public:
    bool checkValidUser(Librarian *librain)
    {
        // if(LibrarianDeatils.find(LibrarianDeatils[librain->getLibrarianID()])!=LibrarianDeatils.end())
        return true;
    }
    bool checkValidLibrarian(User *userid)
    {
        return true;
    }
};

// LibraryManagementSystem Database
class LibraryManagementSystem
{
private:
    int userID;
    string userRqBook;
    string BookId;
    int quentityOfRqBook;
    int quantity;
    // LMSAuthentication *lmsAuthentication;
    //

public:
    LibraryManagementSystem(string userRqBook, string BookId, int quentityOfRqBook, int userID)

    {
        this->userRqBook = userRqBook;
        this->BookId = BookId;
        this->quentityOfRqBook = quentityOfRqBook;
        this->userID = userID;
    }
    bool checkBookAvailability(string BookId)
    {
        return true;
    }
    bool markUserBook(string userRqBook, string BookId, int quentityOfRqBook, int userID)
    {
    }
    bool markBook(string BookID)
    {
        return true;
    }
    bool checkUserBookQuantity(int userID)
    {
        if (quantity > 5)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
class BookDatabase
{
    // unordered_map<BookId, pair<BookName,pair<BookPrice , QuantityOfBook>>>BOOKDETAILS;
private:
    unordered_map<int, pair<string, pair<int, int>>> BOOKDETAILS = {
        {123, {"Python", {320, 10}}},
        {121, {"C++", {420, 6}}},
        {125, {"Java", {320, 5}}}};

public:
    bool checkBookAvailabilityBook(string BookId)
    {
        // BOOKDETAILS.find(BookId) != BOOKDETAILS.end()
        if (1)
        {
            cout << "Yes Book Available "
                 << "And Quantity is : ";
            //  BOOKDETAILS[BookId];
            return true;
        }
        else
        {
            return false;
        }
    }
    bool markBook(string BookID)
    {
        // BOOKDETAILS[BookID].second.second--;
        return true;
    }
};
class UserDatabase
{
    int userId;
    int book_quantity;

private:
    unordered_map<int, pair<string, pair<int, int>>> USERDETAILS = {
        {123, {"Python", {320, 4}}},
        {121, {"C++", {420, 3}}},
        {125, {"Java", {320, 4}}}};

public:
    bool checkUserBookLimit(int id)
    {
        if (book_quantity < 5)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

/*
if new user
create user
else
check any pending due
if true
then give book to user
*/

/*
make a degine in oops c++
Library management system has a book database and hasa user database
and book database has a book detail database and user database has a user  and a libraiasn
*/
// // Displaying books in the database
// cout << "Books in the database:" << endl;
// for ( auto &book : bookDatabase)
// {
//     cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << ", ISBN: " << book.getISBN();
//     if (book.isAvailable())
//         cout << " (Available)" << endl;
//     else
//         cout << " (Not Available)" << endl;
// }

// // Displaying users in the database
// cout << "\nUsers in the database:" << endl;
// for ( auto &user : userDatabase)
// {
//     cout << "Name: " << user.getName() << ", ID: " << user.getID() << endl;
// // }

//     // Creating books
//     Book book1("c++", "user1", "9780743273565");
//     Book book2("Java", "User2", "9780061120084");

//     // Creating users
//     User user1("user1", 1001);
//     User user2("user2", 1002);

//     // Creating librarian
//     Librarian librarian("librain1", 2001);

//     // Adding books and users to databases
//     librarian.addBookToDatabase(bookDatabase, book1);
//     librarian.addBookToDatabase(bookDatabase, book2);

//     librarian.addUserToDatabase(userDatabase, user1);
//     librarian.addUserToDatabase(userDatabase, user2);

//     return 0;