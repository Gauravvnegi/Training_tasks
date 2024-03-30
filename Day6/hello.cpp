/*
"Assignment Tasks :
Solve using OOPS concepts
1: Abstraction
2: Encapsulation
3: Polymorphism
4: Inheritance
5: Association
6: Aggregation
7: Composition
Task 1 :
Write a program to depict Indian Politics.
Consider the politics use cases :
MP: is a person who won from a constituency
getConstituency - return their winning constituency.
getDriver - returns the driver assigned for their vehicle (default car).
exceedsSpendingLimit - returns true or false if Mps exceeds to their spending limit.
PM->Ministers->MP (All of them are MPS) - PM has special permissions such as it can give permission to arrest any minister.
PM enjoys special benefits such as Aircraft (along with car) and its designated driver.
Note: PM spending limit : 1 crore, Ministers: 10 lakhs, MP: 1 lakh.
Need to design in a way  where Commisioner class can arrest MP, Ministers and PM when their expense exceeds their spending limit:
canArrest - can arrest one or many MP.
          Note: If PM  cant arrest.
                If minister can arrest with PM permission
                if mps they can be arrested without anyones permission.
In Short, If the MP is not PM then he can be arrested by commisoner , If he is minister then can be arrested with PMs permisison.

*/
#include <bits/stdc++.h>
using namespace std;
class PM
{
private:
    int spending_limit;
    vector<string> PM_service = {"aircraft_benefit", "CAR"};
    string car_service;
    string driver_name;

public:
    PM(int spending_limit, string car_service, string driver_name)
    {
        this->spending_limit = spending_limit;
        this->car_service = car_service;
        this->driver_name = driver_name;
    }
    bool check_limit(int amount_limit)
    {
        return (amount_limit > spending_limit);
    }
};
class MP
{
private:
    int spending_limit = 100000;
    int amount_limit;

public:
    MP(int amount_limit)
    {
        this->amount_limit = amount_limit;
    }
    bool check_limit(int amount_limit)
    {
        return (amount_limit > spending_limit);
    }
};
class Mininster : public MP
{
private:
    int spending_limit = 1000000;
    int aamount_limit;

public:
    Mininster(int aamount_limit)
    {
        this->aamount_limit = aamount_limit;
    }
    bool check_limit(int aamount_limit)
    {
        return (aamount_limit > spending_limit);
    }
};