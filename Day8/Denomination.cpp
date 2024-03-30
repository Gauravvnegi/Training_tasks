/**
 *Task 1:
 * Intent: user can paint brick in his/her city wall with caption, message and dedicate to someone on Valentine's day.
> Anyone can read content of brick.
> Anyone can comment on it.
> Use cases:
> Brick: Every country has n number of cities and every city can have 1 to n number of walls.
> 1 wall can have max of 90 bricks. 2nd wall would be only initiated once all bricks of 1st wall will be occupied.
> A brick can be only owned by a single guy..
> When owner visits on his/her city wall then his brick should animate.
> Need to find out total number of walls initiated, total number of bricks initiated in specific wall.
> Admin can edit any brick whereas user can edit only his/her brick.
> If more than 10 bricks would be flagged then brick would be in invisible mode.
An owner can dedicate more than one brick to express his/ her love to more than one person whereas a specific brick can be only owned by one person.
Find out hottest guy or girl that received max number of bricks.
Find out the guy or girl that don't get any dedication.
You can input 10 users from command line. Whole project should be able to run through command line.



Task 2 :
As described task is:
You have to create a program for ATM Which would have certain defined denominations of notes : 100 ,200, 500, and 2000 INR.
Now you have to design your ATM in such a way that at any time ATM can be top-up with any required domination like I can add 41000 as (2000 x 20) + (500 x 2) notes
Your ATM should have a function to withdraw cash , input can be any amount:
Use cases for withdraw as below:
1: if amount is not present show error insufficient balance
2: if amount is not in the factor of available denominations show error to ask for multiple of available denomination
3: first largest denomination should be used than smaller : like if I opt for 2300 rs, amount dispatched should be (2000 x 1 ) + (200 x 1) + (100 x 1)
3.b: if any denomination is not there like suppose you don’t have 2000 notes left in ATM , then, amount dispatched should be (500 x 4) + (200 x 1) + (100 x 1)

Next step: it can be done by Modi Ji, that older denomination is not valid in case of demonetization, like 2000 Notes are banned and new 5000 notes are legal , so you code should be like you don’t need to change much of it,
Try to achieve OOPS , and SOLID principles as much as you can,
Also, we will add new use cases to see whether your system can adapt to those changes. If Not, then your design is bad. (SOLID,TRY,YAGNI,KISS)

 */

/*
MARK : Developing Design of ATM Machine
// DESC :
PARAM : UserName,  UserID(ATM Card) , UserOPtion
RESULT : Adding Money , Withdrwing Money

*/
#include <bits/stdc++.h>

using namespace std;

class User
{
private:
    string userName;
    int userID;
    int userOption;

public:
    User(string name, int id, int option) : userName(name), userID(id), userOption(option) {}
    string getUserName()
    {
        return this->userName;
    }
    int getUserID()
    {
        return this->userID;
    }
    int getUserOption()
    {
        return userOption;
    }
};

class ATMDatabase
{
private:
    int ID;
    string password;

public:
    ATMDatabase(int ID, string password) : ID(ID), password(password) {}
    int getID()
    {
        return ID;
    }
    string getPassword()
    {
        return password;
    }
};

class ATMauthenicator
{
public:
    bool checkValidUser(User *user, ATMDatabase *atmDatabase)
    {
        int validID = atmDatabase->getID();
        if (user->getUserID() == validID)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

// Atm class
class ATM
{
public:
    ATMauthenicator authenticator;

    void displayATMfunction(User *user, ATMDatabase *atmDatabase) // Diaplaying the function to the user
    {
        switch (user->getUserOption())
        {
        case 1:
            if (authenticator.checkValidUser(user, atmDatabase))
            {
                cout << "Check Money" << endl;
            }
            break;

        case 2:
            if (authenticator.checkValidUser(user, atmDatabase))
            {
                cout << "Withdraw Money" << endl;
            }
            break;

        case 3:
            if (authenticator.checkValidUser(user, atmDatabase))
            {
                cout << "Input Cash" << endl;
            }
            break;

        case 4:
            if (authenticator.checkValidUser(user, atmDatabase))
            {
                cout << "Change Pin" << endl;
            }
            break;

        default:
            cout << "Invalid option" << endl;
            break;
        }
    }
};

// changing Pin
class ChangePIN
{
private:
    int newPin;

public:
    ATMauthenicator *authenticator;
    ATMDatabase *atmDatabase;
    bool chekVAlidUser(User *user, ATMauthenicator *authenticator)
    {
        if (user->getUserID() == atmDatabase->getID())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

// Showing Denomination of Money
class Denominations
{
private:
    // storing the denomination and number of notes
    // vector<pair<int, int>> denominations;
    map<int, pair<int, int>> denominations;
    int balance = 0;

public:
    Denominations()
    {
        // denominations = {{2000, 0}, {500, 0}, {200, 0}, {100, 0}};
        // balance = 0;
        denominations[1] = {2000, 0};
        denominations[2] = {500, 0};
        denominations[3] = {200, 0};
        denominations[3] = {100, 0};

        balance = 0;
    }
    // Changing the Money After Dmonitization
    bool changeMoney(int previouseMoney, int money_changed, int availableNote)
    {
        if (denominations.find(previouseMoney) != denominations.end())
        {
            denominations[previouseMoney].first = money_changed;
            denominations[previouseMoney].second = availableNote;
            return true;
        }

        cout << "Money Changed " << endl;
        return false;
    }
    // add number of notes
    void addDenominations(int amount, int twoThousand, int fiveHundred, int twoHundred, int hundred)
    {

        denominations[0].second += twoThousand;
        denominations[1].second += fiveHundred;
        denominations[2].second += twoHundred;
        denominations[3].second += hundred;

        balance += amount;

        cout << "Amount added!" << endl;
    }

    // withdraw the amount
    void withdraw(int amountToBeWithdrawed)
    {
        int amount = amountToBeWithdrawed;

        if (amount > this->balance)
        {
            cout << "Insufficient balance." << endl;
            return;
        }

        // vector<int> denomination(this->denominations.size(), 0);

        for (int i = 0; i < denominations.size(); i++)
        {
            int numOfNotes = amount / denominations[i].first;
            if (numOfNotes > denominations[i].second)
            {
                numOfNotes = denominations[i].second;
            }

            amount -= (numOfNotes * denominations[i].first);
            denominations[i].second -= numOfNotes;

            if (amount == 0)
            {
                break;
            }
        }
    }
};

// Demonatization
class Demonatization
{
private:
    vector<pair<Demonatization *, int>> money;
    int changedMoney;
    int availableNotes;
    int previouseMoney;

public:
    Denominations denominations;

    // Initilizing the Demonitization money with Prevoius Money and Available Note
    Demonatization(int previouseMoney, int changedMoney, int availableNotes)
    {
        this->changedMoney = changedMoney;
        this->availableNotes = availableNotes;
        this->previouseMoney = previouseMoney;
    }

    // Changing Money
    void changeDemonatization()
    {
        if (denominations.changeMoney(previouseMoney, changedMoney, availableNotes))
        {
            cout << "Money changed : " << endl;
            return;
        }
        else
        {
            cout << "Error in changing Money" << endl;
            return;
        }
    }
};

///////////////////////////////////

int main()
{
    // Create ATM database
    ATMDatabase atmDatabase(12345, "password");

    // Create a user
    User user("John Doe", 12345, 2);

    ATM atm;
    atm.displayATMfunction(&user, &atmDatabase);

    // Create Denominations object
    Denominations denominations;

    // Add denominations to the ATM
    denominations.addDenominations(10000, 2, 5, 10, 20);

    // Withdraw money from the ATM
    denominations.withdraw(2300);

    // After Demonatization

    // Demonatization demonatization(2000, 5000, 10); // changingNote , NewNote , CountOfNote
    // demonatization.changeDemonatization();

    return 0;
}
