// Create a whats app as following
// Users have contacts and can chat with any contact
// Messaging in text audio and video
// Users can see the status of all the contacts
// Users can post status
// Status can be text and image
/*
watsapp has usermanagement and  usermanagement has
user ,and user has status , message , contact and status is a image , status is a text , message is a audio , message is a
viedo , user has a post
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Person
{
public:
    string name;
    string phoneNo;

    Person() {}
    Person(string _name, string _phoneNo) : name(_name), phoneNo(_phoneNo) {}

    string getName() { return name; }
    string getPhoneNo() { return phoneNo; }
};

class User : public Person
{
private:
    string userName;
    int userContactNumber;
    vector<Contact *> contacts;
    string message;
    // vector<Status *> status;
    // vector<Post *> post;
    Status *status;

public:
    User(string name, int userNumber) : userName(name), userContactNumber(userNumber) {}

    string getUserName() { return userName; }
    int getUserContactNumber() { return userContactNumber; }

    bool addContact(Contact *newContact)
    {
        contacts.push_back(newContact);
        return true;
    }

    void setMessage(string _message) { message = _message; }
    string getMessage() { return message; }

    bool addStatus(Status *newStatus)
    {
        status = newStatus;
        return true;
    }
};

class Status
{
private:
    unordered_map<User *, string> userStatus;
    string statusContent;

public:
    bool statusType;

    void setStatus(User *user, string content)
    {
        userStatus[user] = content;
    }

    void showUserStatus()
    {
        for (auto it = userStatus.begin(); it != userStatus.end(); ++it)
        {
            cout << it->first->getUserName() << ": " << it->second << endl;
        }
    }
};

class Text : public Status
{
private:
    string text;

public:
    void setText(string _text) { text = _text; }
    string getText() { return text; }
};

class Image : public Status
{
private:
    string image;

public:
    void setImage(string _image) { image = _image; }
    string getImage() { return image; }
};

class Contact : public Person
{
public:
    Contact(string name, string number) : Person(name, number) {}

    void showUserContact()
    {
        cout << "User Contact" << endl;
    }
};

class Message
{
private:
    string message;
    Contact *contact;

public:
    void setMessage(string _message, Contact *_contact)
    {
        message = _message;
        contact = _contact;
    }

    void showUserMessage()
    {
        cout << "User Message" << endl;
    }

    string getMessage() { return message; }
};

int main()
{

    User user1("amit", 1234567890);
    User user2("arjun", 9876543210);

    Contact contact1("user1", "1112223333");
    Contact contact2("User2", "4445556666");

    Message message1;
    message1.setMessage("Hello, how are you?", &contact1);

    Status status1;
    Text textStatus;
    textStatus.setText("Feeling great today!");
    status1.setStatus(&user1, textStatus.getText());

    cout << "User 1 Name: " << user1.getName() << ", Phone: " << user1.getPhoneNo() << endl;
    cout << "User 2 Name: " << user2.getName() << ", Phone: " << user2.getPhoneNo() << endl;

    cout << "Contact 1 Name: " << contact1.getName() << ", Phone: " << contact1.getPhoneNo() << endl;
    cout << "Contact 2 Name: " << contact2.getName() << ", Phone: " << contact2.getPhoneNo() << endl;

    cout << "Message: " << message1.getMessage() << endl;

    cout << "User 1 Status: ";
    status1.showUserStatus();

    return 0;
}