/*
Task 1:
Intent: user can paint brick in his/her city wall with caption, message and dedicate to someone on Valentine's day.
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
A plateform has a usermanagement ans a Brick management  ans user has a user managemnet where he can create delete update,
delete post and brcik has brick management where brick managemnet can edit delete , create , view user details and this is done by admin , owner degine this in oops cpp

*/

/*
MARK : Developing Design of ATM Machine
// DESC :
PARAM : UserName,  UserID , cityName , userNmberOfBrick
RESULT : Finding out the girl with max number of bricks.

*/
#include <bits/stdc++.h>
using namespace std;
// User Class

class User
{
protected:
    int ID;
    string userName;
    int numBricksOwned;
    string cityName;
    string Password;

public:
    User(int id, string userName, int numBricksOwned, string cityName) ///
    {
        this->ID = id;
        this->userName = userName;
        this->numBricksOwned = numBricksOwned;
        this->cityName = cityName;
    }

    int getID()
    {
        return ID;
    }
    string getName()
    {
        return userName;
    }
    int getNumBricksOwned()
    {
        return numBricksOwned;
    }
    string getCityName()
    {
        return cityName;
    }
    string getPass()
    {
        return Password;
    }
    void setName(string &userName)
    {
        this->userName = userName;
    }
    void incrementNumBricksOwned()
    {
        numBricksOwned++;
    }
    bool checkValidation()
    {
        return true;
    }
};

// Brick Class
class Brick
{
private:
    int ID;
    User *owner;
    string caption;
    string message;
    string dedication;
    bool visibilityStatus;
    int flagCount;

public:
    // (1, users[0], "Caption1", "Message1", "Dedication1")
    Brick(int id, User *owner, string caption, string message, string dedication)
    {
        this->ID = id;
        this->owner = owner;
        this->caption = caption;
        this->message = message;
        this->dedication = dedication;
    }

    void setCaption(string &cap)
    {
        caption = caption;
    }
    void setMessage(string &msg)
    {
        message = message;
    }
    void setDedication(string &ded)
    {
        dedication = dedication;
    }
    void flag()
    {
        flagCount++;
    }
    void animate()
    {
        cout << "Animating brick with ID " << ID << endl;
    }
    int getID()
    {
        return ID;
    }
    User *getOwner()
    {
        return owner;
    }
    string getCaption()
    {
        return caption;
    }
    string getMessage()
    {
        return message;
    }
    string getDedication()
    {
        return dedication;
    }
    bool getVisibilityStatus()
    {
        return visibilityStatus;
    }
    int getFlagCount()
    {
        return flagCount;
    }
};

// Admin Class

class Admin
{
    int id = 123;
    string pass = "123";

public:
    void editBrick(User *currentUser, Brick *brick, string caption, string message, string dedication)
    {
        if (currentUser == brick->getOwner())
        {
            brick->setCaption(caption);
            brick->setMessage(message);
            brick->setDedication(dedication);
            cout << "Brick edited successfully." << endl;
        }
        else
        {
            cout << "You don't have permission to edit this brick." << endl;
        }
    }
    int getID()
    {
        return id;
    }
    string getPass()
    {
        return pass;
    }
};

// Athentication of User

class Authentication
{
    // User *owner;
    int id;
    string pass;

public:
    bool checkValidationOfUser(User *owner)
    {
        // id = owner->getID();
        // pass = owner->getPass();
        if (id == owner->getID() && pass == owner->getPass()) // checking for valid user
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool checkValidationOfAdmin(Admin *admin)
    {
        // id = admin->getID();
        // pass = admin->getPass();
        if (id == admin->getID() && pass == admin->getPass()) // checking for valid admin
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
class Wall
{
private:
    int ID;
    vector<Brick *> bricks;

public:
    Wall(int id) : ID(id) {}

    // Methods
    void addBrick(Brick *brick)
    {
        if (bricks.size() < 90)
        {
            bricks.push_back(brick);
        }
        else
        {
            cout << "Wall is full Not able to add add more bricks." << endl;
        }
    }

    int getTotalBricks()
    {
        return bricks.size();
    }

    void animateOwnerBrick(User *user)
    {
        for (auto brick : bricks)
        {
            if (brick->getOwner() == user)
            {
                brick->animate();
            }
        }
    }

    int getBrickCount()
    {
        return bricks.size();
    }
    int getID()
    {
        return ID;
    }
};

class Country
{
private:
    string countryName;

public:
    string setCountryName(string &countryName)
    {
        this->countryName = countryName;
    }
    string getCountryName()
    {
        return countryName;
    }
};
class City : public Country
{
private:
    vector<Wall *> walls;
    string CityName;

public:
    // Methods
    void addWall(Wall *wall)
    {
        walls.push_back(wall);
    }

    int getTotalWalls()
    {
        return walls.size();
    }

    int getBrickCountInWall(int wallID)
    {
        int count = 0;
        for (auto wall : walls)
        {
            if (wall->getID() == wallID)
            {
                count += wall->getTotalBricks();
            }
        }
        return count;
    }
    string setCityName(string &CityName)
    {
        this->CityName = CityName;
    }
    string getCityName()
    {
        return CityName;
    }
};

// Location of user
class UserLocation
{
private:
    string userLocation;

public:
    UserLocation(string &UserLocation) : userLocation(userLocation) {}
    string getLocation()
    {
        return userLocation;
    }
};

int main()
{
    // Create some users and bricks for testing
    vector<User *> users;
    users.push_back(new User(1, "User1", 10, "Noida"));
    users.push_back(new User(2, "User2", 20, "New Delhi"));
    users.push_back(new User(3, "User3", 1, "New Delhi"));

    vector<Brick *> bricks;
    // int id, User *owner, string caption, string message, string dedication
    bricks.push_back(new Brick(1, users[0], "Caption1", "Message1", "Dedication1"));
    bricks.push_back(new Brick(2, users[1], "Caption2", "Message2", "Dedication2"));
    bricks.push_back(new Brick(3, users[0], "Caption3", "Message3", "Dedication3"));
    // bricks.push_back(new Brick(4, users[0], "Caption4", "Message4", "Dedication4"));
    bricks.push_back(new Brick(5, users[2], "Caption5", "Message5", "Dedication5"));
    // bricks.push_back(new Brick(6, users[1], "Caption6", "Message6", "Dedication6"));
    // bricks.push_back(new Brick(7, users[1], "Caption7", "Message7", "Dedication7"));

    // Count number of bricks per user
    unordered_map<User *, int> bricksCount;
    for (Brick *brick : bricks)
    {
        bricksCount[brick->getOwner()]++;
    }

    // Find the girl with the maximum number of bricks
    User *hottestUser;
    int maxBricks = 0;
    for (auto &itr : bricksCount)
    {
        if (itr.second > maxBricks)
        {
            hottestUser = itr.first;
            maxBricks = itr.second;
        }
    }

    if (hottestUser != NULL)
    {
        cout << "The hottest user is: " << hottestUser->getName() << " with " << maxBricks << " bricks." << endl;
    }
    else
    {
        cout << "No bricks found." << endl;
    }

    return 0;
}
/*
/**
 * // UserManagement userManagement;
    // BrickManagement brickManagement;

    // userManagement.createUser("user1");
    // brickManagement.createBrick("Brick 1 content");
    // Plateform platform;

    // // Creating user and brick through platform
    // platform.getUserManagement().createUser("user1");
    // platform.getBrickManagement().createBrick("Brick 1 content");

    // // Adding brick to wall through platform
    // platform.getWall().addBrick(platform.getBrickManagement().getBricks().back());

    // Add brick to wall
    // Wall wall;
    // wall.addBrick(brickManagement.getBrick(0)); // Assuming getBrick method is implemented
 *
 */