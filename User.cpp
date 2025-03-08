// TO DO: #include needed standard libraries and your own libraries here
#include <string>
#include "User.h"

// TO DO: function implementations
// TODO(emma): If the default constructor needs to populate fields, implement it here.
// User::User() {}

// Operator == overloading implementation
bool User::operator==(const User& otherUser) const {
	return (User::username == otherUser.username) && (User::email == otherUser.email);
}

std::string User::getUsername() const {
	return User::username;
}
