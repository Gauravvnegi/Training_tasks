/**
Day2-OOPS
Parking Lot Design
A parking lot or car park is a dedicated cleared area that is intended for parking vehicles.
Use case
Here are the main Actors in our system:
Admin: Mainly responsible for adding and modifying parking floors, parking spots, entrance, and exit panels,
adding/removing parking attendants, etc.
Customer: All customers can get a parking ticket and pay for it.
Parking attendant: Parking attendants can do all the activities on the customer’s behalf, and can take cash for ticket payment.
System: To display messages on different info panels, as well as assigning and removing a vehicle from a parking spot.
Here are the top use cases for Parking Lot:
Add/Remove/Edit parking floor: To add, remove or modify a parking floor from the system. Each floor can
have its own display board to show free parking spots.
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
Customers should also be able to pay the parking fee at the customer’s info portal on each floor. If the customer
has paid at the info portal, they don’t have to pay at the exit.
The system should not allow more vehicles than the maximum capacity of the parking lot.
If the parking is full, the system should be able to show a message at the entrance panel and on the parking display board on the ground floor.
Each parking floor will have many parking spots. The system should support multiple types of parking spots
such as Compact, Large, Handicapped, Motorcycle, etc.
The Parking lot should have some parking spots specified for electric cars. These spots should have an electric
panel through which customers can pay and charge their vehicles.
The system should support parking for different types of vehicles like car, truck, van, motorcycle, etc.
Each parking floor should have a display board showing any free parking spot for each spot type.
The system should support a per-hour parking fee model. For example, customers have to pay $4 for the first hour,
$3.5 for the second and third hours, and $2.5 for all the remaining hours.
 */
#include <bits/stdc++.h>
using namespace std;
class Parking
{
public:
    int floor = 3;
    int total_spot = 78;
    map<int, pair<pair<string, string>, int>> track_parking_spot;
};
// Admin: Mainly responsible for adding and modifying parking floors, parking spots, entrance, and exit panels,
// adding/removing parking attendants, etc
class ParkingLot
{
public:
    map<pair<string, string>, vector<int>> Floor_parking_detail;
    map<int, int> spot; // parkinglot number ,
    // map<int,>;
public:
    ParkingLot()
    {
        Floor_parking_detail[{"floor1", "compact"}].push_back(5);     // Compact
        Floor_parking_detail[{"floor1", "Large"}].push_back(6);       // Large
        Floor_parking_detail[{"floor1", "Handicapped"}].push_back(2); // Handicapped
        Floor_parking_detail[{"floor1", "motocycle"}].push_back(5);   // Motorcycle
        // floor 2 parking size;
        Floor_parking_detail[{"floor2", "compact"}].push_back(4);     // Compact
        Floor_parking_detail[{"floor1", "Large"}].push_back(3);       // Large
        Floor_parking_detail[{"floor3", "Handicapped"}].push_back(3); // Handicapped
        Floor_parking_detail[{"floor1", "motocycle"}].push_back(6);   // Motorcycle

        // floor3 parking size;
        Floor_parking_detail[{"floor3", "compact"}].push_back(8);      // Compact
        Floor_parking_detail[{"floor1", "Large"}].push_back(10);       // Large
        Floor_parking_detail[{"floor3", "Handicapped"}].push_back(20); // Handicapped
        Floor_parking_detail[{"floor1", "motocycle"}].push_back(6);    // Motorcycle
    }
};
class Fee : public Parking
{
public:
    map<int, int> cost_caculate;
    int amount;
    Fee()
    {
        cost_caculate[1] = 4;
        cost_caculate[2] = 3.5;
        cost_caculate[3] = 2.5;
    }
    void Calculate_price(int id_number)
    {
        for (auto it : track_parking_spot)
        {
            if (track_parking_spot.find(id_number) != track_parking_spot.end())
            {
                auto total_hours = it.second.second;
                auto car_model = it.second.first;

                if (total_hours == 1)
                {
                    cout << "Your total cost is : " << cost_caculate[1] << endl;
                    cout << "Your car id : " << id_number << endl;
                    cout << "Thankyou" << endl;
                    amount = cost_caculate[1];
                    track_parking_spot.erase(id_number);
                }
                else if (total_hours == 2)
                {
                    cout << "Your total cost is : " << cost_caculate[2] << endl;
                    cout << "Your car id : " << id_number << endl;
                    // cout<<"Your car model is : "<<car_model<<endl;
                    cout << "Thankyou" << endl;
                    amount = cost_caculate[2];
                    track_parking_spot.erase(id_number);
                }
                else
                {
                    int remaining_hours = total_hours - 2;
                    int total_cost = remaining_hours * 2.3 + 4 + 3.5;
                    cout << "Your total cost is : " << total_cost << endl;
                    cout << "Your car id : " << id_number << endl;
                    cout << "Thankyou" << endl;
                    amount = cost_caculate[2];
                    track_parking_spot.erase(id_number);
                }
            }
        }
    }
};
class Payment : public Fee
{
public:
    vector<pair<int, string>> payment_option; // type -- online , cash

    void payment_options(int option, string floor)
    {
        if (option == 1)
        {
            if (floor == "Floor1")
            {
                cout << "Paying online ammount is : " << amount;
                cout << "Your exit gate is 1 , 4" << endl;
            }
            else if (floor == "Floor2")
            {
                cout << "Paying online ammount is : " << amount;
                cout << "Your exit gate is 5 , 8" << endl;
            }
            else
            {
                cout << "Paying online ammount is : " << amount;
                cout << "Your exit gate is 9 , 10" << endl;
            }
        }
        else
        {
            if (floor == "Floor1")
            {
                cout << "Paying Cash ammount is : " << amount;
                cout << "Your exit gate is 1 , 4" << endl;
            }
            else if (floor == "Floor2")
            {
                cout << "Paying Cash ammount is : " << amount;
                cout << "Your exit gate is 5 , 8" << endl;
            }
            else
            {
                cout << "Paying Cash ammount is : " << amount;
                cout << "Your exit gate is 9 , 10" << endl;
            }
        }
    }
};
class Admin : public ParkingLot, public Fee
{
private:
    int adding = 0;
    int modifying_floor = 0;
    int parking_spots = 0;
    int entrance;
    int exit_panels;
    map<int, pair<string, string>> find_parking_spot;
    // id - > car - > type(compact etc)
    int vechical_spot_id = 0;
    int count_vechical_variety = 1;

public:
    void adding_cars(string car_name_type, string car_name, string vechicle_type)
    {

        for (auto it : Floor_parking_detail)
        {
            if (vechicle_type == "compact" && vechical_spot_id < 78)
            {
                for (auto it : track_parking_spot)
                {
                    if (track_parking_spot.find(vechical_spot_id) == track_parking_spot.end())
                    {
                        cout << "Your id is : " << vechical_spot_id << endl;
                        cout << "You can park at : " << vechical_spot_id << endl;
                        vechical_spot_id++;
                    }
                    else
                    {
                        break;
                    }
                }
                auto floor = it.first;
                if (it.second[0] != 0)
                {
                    cout << "Space is free you can park " << endl;
                    if (count_vechical_variety == 1)
                    {
                        cout << "Your parking spot is in first floor and Entry gate number is 1 or 3" << endl;
                    }

                    track_parking_spot[vechical_spot_id] = {{car_name, vechicle_type}, 3};
                }
            }
            else if (vechicle_type == "Large" && vechical_spot_id < 78)
            {
                auto floor = it.first;
                if (it.second[1] != 0)
                {
                    cout << "Space is free you can park " << endl;
                    if (count_vechical_variety == 2)
                    {
                        cout << "Your parking spot in second floor Entry gate number is 4 or 5" << endl;
                        count_vechical_variety++;
                    }
                    for (auto it : track_parking_spot)
                    {
                        if (track_parking_spot.find(vechical_spot_id) != track_parking_spot.end())
                        {
                            cout << "Your id is : " << vechical_spot_id << endl;
                            vechical_spot_id++;
                        }
                        break;
                    }
                    track_parking_spot[vechical_spot_id] = {{car_name, vechicle_type}, 3};
                }
            }
            if (vechicle_type == "Handicapped" && vechical_spot_id < 78)
            {
                auto floor = it.first;
                if (it.second[2] != 0)
                {
                    cout << "Space is free you can park " << endl;
                    if (count_vechical_variety == 3)
                    {
                        cout << "Your parking spot in third floor Entry gate number is 10 or 11" << endl;
                        count_vechical_variety++;
                    }
                    for (auto it : track_parking_spot)
                    {
                        if (track_parking_spot.find(vechical_spot_id) != track_parking_spot.end())
                        {
                            cout << "Your id is : " << vechical_spot_id << endl;
                            vechical_spot_id++;
                        }
                        break;
                    }
                }
                track_parking_spot[vechical_spot_id] = {{car_name, vechicle_type}, 3};
            }
            if (vechicle_type == "motocycle" && vechical_spot_id < 78)
            {
                auto floor = it.first;
                if (it.second[3] != 0)
                {
                    cout << "Space is free you can park " << endl;
                    if (count_vechical_variety == 3)
                    {
                        cout << "Your parking spot in third floor Entry gate number is 10 or 11" << endl;
                        count_vechical_variety++;
                    }
                    for (auto it : track_parking_spot)
                    {
                        if (track_parking_spot.find(vechical_spot_id) != track_parking_spot.end())
                        {
                            cout << "Your id is : " << vechical_spot_id << endl;
                            vechical_spot_id++;
                        }
                        break;
                    }
                }
                // parkingSpotMap[vehicleSpotId] = {{carName, vehicleType}, 3};
                track_parking_spot[vechical_spot_id] = {{car_name, vechicle_type}, 4};
            }
        }
    }
};
int main()
{
    Parking parking;
    ParkingLot parkinglot;
    Payment fee;
    // string car_name_type, string car_name, string vechicle_type
    Admin car1;
    car1.adding_cars("BMW", "BM", "compact");
    fee.Calculate_price(2);
}