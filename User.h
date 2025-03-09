#ifndef USER_
#define USER_

#include <string>

class User {
private:
    std::string username;
    std::string email;
    std::string password; //added
    std::string bio;  //added
    std::string profilePicture; //added

public:
    // Declare functions (do not define them here)
    bool operator==(const User& otherUser) const;
    std::string getUsername() const;
    void displayProfile() const; //added

    User(); 
    User(const std::string& username, const std::string& email, const std::string& password,
         const std::string& bio, const std::string& profilePicture); //added

    User(const std::string& username, const std::string& email); //added

};

#include "User.cpp"
#endif
