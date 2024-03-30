/*
Task 2:
suppose you are making a program for a very famous IoT Inverter company,
company have multiple inverters with multiple business logic,
use cases:
company have PCU, GTI, Zelio, Regalia, iCruze Inverters,
All Inverters have Power rating which is determined by ( Current * Operating Voltage )
Only PCU, GTI and Regalia are solar Inverters other are not (solar inverters get charge by solar panels and solar energy),
Solar Inverters have Solar Panels also
Solar Inverters further have two option one Battery version that whatever energy is produced will be stored in battery other will not store any energy,
so PCU comes with battery but GTI have no battery,
Solar Inverter also have GRID On , system where you can sell your extra energy back, GTI is GRID On where as this feature is not available in PCU,
Non Solar Inverters are Simple Home Inverters Which have a Battery,"
*/
#include <bits/stdc++.h>
// Base class for all inverters
using namespace std;
class Inverter
{

protected:
    string type;
    double current;
    double operatingVoltage;

public:
    Inverter(const string &type, double current, double operatingVoltage) : type(type), current(current), operatingVoltage(operatingVoltage) {}

    virtual double calculatePowerRating() const = 0; // Pure virtual function for polymorphism

    string getType() const
    {
        return type;
    }
};

// SolarPanel class for solar inverters
class SolarPanel
{
private:
    double efficiency;

public:
    SolarPanel(double efficiency) : efficiency(efficiency) {}

    double getEfficiency() const
    {
        return efficiency;
    }
};

// Battery class
class Battery
{
private:
    double capacity;

public:
    Battery(double capacity) : capacity(capacity) {}

    double getCapacity() const
    {
        return capacity;
    }
};

// PCU (Power Conditioning Unit) class, inherits from Inverter
class PCU : public Inverter
{
private:
    string batteryList;

public:
    PCU(double current, double operatingVoltage, double batteryCapacity) : Inverter("PCU", current, operatingVoltage), battery(batteryCapacity) {}

    double calculatePowerRating() const override
    {
        return current * operatingVoltage;
    }
};

// GTI (Grid-Tied Inverter) class, inherits f
class GTI : public Inverter
{
private:
    SolarPanel solarPanel;

public:
    GTI(double current, double operatingVoltage, double solarPanelEfficiency)
        : Inverter("GTI", current, operatingVoltage), solarPanel(solarPanelEfficiency) {}

    double calculatePowerRating() const override
    {
        return current * operatingVoltage;
    }
};

// Regalia class, inherits from Inverter
class Regalia : public Inverter
{
private:
    SolarPanel solarPanel;
    Battery battery;

public:
    Regalia(double current, double operatingVoltage, double solarPanelEfficiency, double batteryCapacity)
        : Inverter("Regalia", current, operatingVoltage), solarPanel(solarPanelEfficiency), battery(batteryCapacity) {}

    double calculatePowerRating() const override
    {
        return current * operatingVoltage;
    }
};

// iCruze class, inherits from Inverter
class iCruze : public Inverter
{
public:
    iCruze(double current, double operatingVoltage)
        : Inverter("ICruze", current, operatingVoltage) {}

    double calculatePowerRating() const override
    {
        return current * operatingVoltage;
    }
};

// Main function for testing
int main()
{
    PCU pcu(10.0, 220.0, 100.0); // current , operatingvoltage ,batterycapacity
    GTI gti(15.0, 220.0, 0.85);
    Regalia regalia(20.0, 220.0, 0.90, 150.0);
    iCruze icruze(5.0, 220.0);

    cout << "PCU Power Rating: " << pcu.calculatePowerRating() << endl;
    cout << "GTI Power Rating: " << gti.calculatePowerRating() << endl;
    cout << "Regalia Power Rating: " << regalia.calculatePowerRating() << endl;
    cout << "ICruze Power Rating: " << icruze.calculatePowerRating() << endl;

    return 0;
}
