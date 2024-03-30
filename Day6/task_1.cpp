#include <iostream>
#include <string>
#include <map>
using namespace std;

// Base class for politicians
class Politician
{
protected:
    string constituency;
    double expenditure; // Stores the expenditure

public:
    Politician(const string &constituency)
    {
        this->constituency = constituency;
        expenditure = 0;
    }

    string getConstituency() const
    {
        return constituency;
    }

    void addExpenditure(double amount)
    {
        expenditure += amount;
    }

    double getExpenditure() const
    {
        return expenditure;
    }

    virtual string getType() const = 0;
};

// MP class, inheriting from Politician
class MP : public Politician
{
public:
    MP(const string &constituency) : Politician(constituency) {} // MP spending limit: 1 lakh

    string getType() const override
    {
        return "MP";
    }
};

// Minister class, inheriting from MP
class Minister : public MP
{
public:
    Minister(const string &constituency) : MP(constituency) {} // Minister spending limit: 10 lakhs

    string getType() const override
    {
        return "Minister";
    }
};

// Prime Minister class, inheriting from Minister
class PrimeMinister : public Minister
{
private:
    string driver_name;
    string car_model;

public:
    PrimeMinister(const string &constituency, string driver_name, string car_model)
        : Minister(constituency), driver_name(driver_name), car_model(car_model) {} // PM spending limit: 1 crore

    string getType() const override
    {
        return "Prime Minister";
    }
};

// Commissioner class
class Commissioner
{
private:
    map<string, double> spendingLimits;

public:
    Commissioner()
    {
        spendingLimits["MP"] = 100000;
        spendingLimits["Minister"] = 1000000;
        spendingLimits["Prime Minister"] = 10000000;
    }

    void canArrest(const Politician &politician)
    {
        double expenses = politician.getExpenditure();
        string type = politician.getType();

        if (expenses > spendingLimits[type])
        {
            cout << "Commissioner can arrest the " << type << "." << endl;
        }
        else
        {
            cout << "Commissioner cannot arrest the " << type << "." << endl;
        }
    }
};

int main()
{
    // Test cases
    MP mp("UK");
    Minister minister("Mumbai");
    PrimeMinister pm("Delhi", "BMW", "Deepak");

    // Adding expenditures for testing
    mp.addExpenditure(15000);         // Exceeds MP limit
    minister.addExpenditure(1000001); // Exceeds Minister limit
    pm.addExpenditure(900000);        // Exceeds PM limit

    Commissioner commissioner;
    commissioner.canArrest(mp);
    commissioner.canArrest(minister);
    commissioner.canArrest(pm);

    return 0;
}
