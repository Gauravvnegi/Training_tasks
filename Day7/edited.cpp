/*
Parking Lot Design
A parking lot or car park is a dedicated cleared area that is intended for parking vehicles.
Use case
Here are the main Actors in our system:
Admin: Mainly responsible for adding and modifying parking floors, parking spots, entrance, and exit panels, adding/removing parking attendants, etc.
Customer: All customers can get a parking ticket and pay for it.
Parking attendant: Parking attendants can do all the activities on the customer’s behalf, and can take cash for ticket payment.
System: To display messages on different info panels, as well as assigning and removing a vehicle from a parking spot.
Here are the top use cases for Parking Lot:
Add/Remove/Edit parking floor: To add, remove or modify a parking floor from the system. Each floor can have its own display board to show free parking spots.
Add/Remove/Edit parking spot: To add, remove or modify a parking spot on a parking floor.
Add/Remove a parking attendant: To add or remove a parking attendant from the system.
Take ticket: To provide customers with a new parking ticket when entering the parking lot.
Scan ticket: To scan a ticket to find out the total charge.
Credit card payment: To pay the ticket fee with credit card.
Cash payment: To pay the parking ticket through cash.
Add/Modify parking rate: To allow admin to add or modify the hourly parking rate

System Requirements
We will focus on the following set of requirements while designing the parking lot:
The parking lot should have multiple floors where customers can park their cars.
The parking lot should have multiple entry and exit points.
Customers can collect a parking ticket from the entry points and can pay the parking fee at the exit points on their way out.
Customers can pay the tickets at the automated exit panel or to the parking attendant.
Customers can pay via both cash and credit cards.
Customers should also be able to pay the parking fee at the customer’s info portal on each floor. If the customer has paid at the info portal, they don’t have to pay at the exit.
The system should not allow more vehicles than the maximum capacity of the parking lot. If the parking is full, the system should be able to show a message at the entrance panel and on the parking display board on the ground floor.
Each parking floor will have many parking spots. The system should support multiple types of parking spots such as Compact, Large, Handicapped, Motorcycle, etc.
The Parking lot should have some parking spots specified for electric cars. These spots should have an electric panel through which customers can pay and charge their vehicles.
The system should support parking for different types of vehicles like car, truck, van, motorcycle, etc.
Each parking floor should have a display board showing any free parking spot for each spot type.
The system should support a per-hour parking fee model. For example, customers have to pay $4 for the first hour, $3.5 for the second and third hours, and $2.5 for all the remaining hours.
*/
#include <bits/stdc++.h>

using namespace std;
class admin
{
private:
    vector<admin *> floor;
    int number_of_floor;
    int numbe_of_spots;

private:
    // Increasing the FLoor
    int IncreaseFloor()
    {
        return number_of_floor;
    }
    // Increasing Number of Spot in the floor
    int NumberOfSpots()
    {
        return numbe_of_spots;
    }
};

class user
{
private:
    string name; // Name
    string type; // Type of Car
    int hour;    // How much time

public:
    user(string name, string type, int hour)
    {
        this->name = name;
        this->type = type;
        this->hour = hour;
    }

    string getName()
    {
        return name;
    }

    string getType() const
    {
        return type; // Returning the type example Large,Compact,handicapped,motercycle
    }

    int getHour()
    {
        return hour; // returning the total number of hours of parking
    }
    ~user() {} // Dynamically removing the space
};

// Ticket class
class Ticket
{
private:
    string id;
    int hour;

public:
    Ticket(string id) : id(id) {}

    string getId() const
    {
        return id; // Returning the id of ticket
    }

    int getHour() const
    {
        return hour;
    }
};
// Payment class which in inherited from base class Ticket
class Payment : public Ticket
{
public:
    bool virtual paymentMethod() = 0;
};

// types of payment according to user choice
class Cash : public Payment
{
    int amount;

public:
    bool payCash()
    {
        return amount;
    }
    bool paymentMethod()
    {
        return true;
    }
};

// types of payment according to user choice
class Online : public Payment
{
    int amount;
    vector<pair<string, vector<string>>> onlinePaymentType = {
        {"UPI", {"Paytm", "PhonePay", "GooglePay"}}};

public:
    bool payOnline()
    {
        return amount;
    }
    bool paymentMethod()
    {
        return true;
    }
};

// Parking Lot class of parking the cars
// class Entry;
class Entry
{
private:
    map<string, int> entry_point = {{"compact", 0}, {"Handicapped", 2}, {"Motorcycle", 3}, {"Large", 4}};
    vector<int> floors;
    int floornumber;

public:
    int getEntrytPoint(string typeOfCar)
    {
        return entry_point[typeOfCar];
    }
    int getFloorNumber()
    {
        return floornumber;
    }
};
// Displaing Map of Praking Lot
class ParkingLotMap
{
public:
    void DisplayMap()
    {
        // Logic For Displaying parking Lot map
    }
};

// Parking Lot Class
class ParkingLot
{
protected:
    unordered_map<string, int> availableSpaces;
    unordered_map<string, pair<string, string>> data_of_vechicle;
    set<string> valid_ticket;
    Entry obj;

public:
    ParkingLot()
    {
        // Initialize available spaces for each car type
        availableSpaces["Large"] = 10;
        availableSpaces["Compact"] = 2;
        availableSpaces["Handicapped"] = 5;
        availableSpaces["Motorcycle"] = 15;
    }

    bool isSpaceAvailable(const string &type)
    {
        return availableSpaces[type] > 0; // Returning true if there is any space available space for that car variety
    }

    Ticket generateTicket(user &car)
    {
        availableSpaces[car.getType()]--;
        string ticket_generate = "T" + to_string(rand());                   // Generating the random ticket
        data_of_vechicle[ticket_generate] = {car.getName(), car.getType()}; // Storing the car detail
        valid_ticket.insert(ticket_generate);
        cout << "Your Entry Point is : "
             << " "
             << " " << obj.getEntrytPoint(car.getType());
        return Ticket("T" + to_string(rand())); // Generating a random ticket id
    }
    // Checking for valid Ticket
    bool isValidTicket(Ticket &ticket)
    {
        for (auto it : valid_ticket)
        {
            if (valid_ticket.find(ticket.getId()) != valid_ticket.end()) // Checking for invalid ticket
            {
                cout << "Invalid Ticket" << endl;
                return false;
            }
        }
        cout << "Valid Ticket" << endl;
        return true;
    }

    double calculateParkingCost(Ticket &ticket) // Calculation for ticket amount
    {
        if (ticket.getHour() == 1)
        {
            return 4.0;
        }
        else if (ticket.getHour() == 2)
        {
            return 3.5;
        }
        double remaining_hours = remaining_hours - 3;
        double total_cost = remaining_hours * 2.5;
        return abs(total_cost);
    }

    void removeCar(user &car) // removing the car after exit
    {
        availableSpaces[car.getType()]++;
    }

    void parkCar(user &car)
    {
        if (isSpaceAvailable(car.getType()))
        {
            Ticket ticket = generateTicket(car);
            if (ticket.getId() != "")
            {
                cout << "Ticket ID: " << ticket.getId() << endl;
            }
        }
        else
        {
            cout << "No space available for the car type." << endl;
        }
    }
};

// Exit class
class Exit : public ParkingLot
{
public:
    void exitParking(ParkingLot &parkingLot, user &car) // Checking for parking Space
    {
        Ticket ticket = generateTicket(car);
        if (parkingLot.isValidTicket(ticket))
        {
            double cost = parkingLot.calculateParkingCost(ticket);
            cout << "Parking cost: $" << cost << endl;
            parkingLot.removeCar(car);
            data_of_vechicle.erase(car.getType());
            cout << ticket.getId() << " Exited successfully." << endl;
        }
        else
        {
            cout << "Invalid ticket." << endl; // Returning for invalid ticket
        }
    }
};
// Car Varification
class Varification
{
public:
    bool ticketVarification(user *user, Ticket &ticket)
    {
        return (user->getType() == ticket.getId());
    }
};

// main Fucntion
int main()
{
    ParkingLot parkingLot;

    user adm("adm1", "Compact", 1);
    user adm1("A", "Compact", 1);
    // user adm2("asdfasd", "Compact", 1);

    // user adm3("B", "Compact", 4);
    parkingLot.parkCar(adm);
    parkingLot.parkCar(adm1);
    // parkingLot.parkCar(adm2);

    Exit exit;
    // ParkingLot parkingLot;
    exit.exitParking(parkingLot, adm);
    // exit.exitParking(parkingLot, adm1);
    return 0;
}
// parking cost  -$ 1.62192e+007