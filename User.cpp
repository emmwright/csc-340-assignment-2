// TO DO: #include needed standard libraries and your own libraries here
#include <string>
#include <iostream> //added this 
#include "User.h"

// Default constructor
User::User() : username(""), email(""), password(""), bio(""), profilePicture("") {} //added this

// Parameterized constructor
User::User(const std::string& username, const std::string& email, const std::string& password, //added this 
           const std::string& bio, const std::string& profilePicture) //added
    : username(username), email(email), password(password), bio(bio), profilePicture(profilePicture) {} //added

// Equality operator
bool User::operator==(const User& otherUser) const {
    return (username == otherUser.username) && (email == otherUser.email);
}

//Getter function
std::string User::getUsername() const {
    return username;
}

void User::displayProfile() const { //added all this
    std::cout << "Username: " << username <<
                 "\nEmail: " << email << 
                 "\nPassword: " << password <<
                 "\nBio: " << bio <<
                 "\nProfile Picture: " << profilePicture << std::endl;
}
