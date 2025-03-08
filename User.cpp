// TO DO: #include needed standard libraries and your own libraries here
#include "User.h"

// TO DO: function implementations
User::User() {}

// Operator == overloading implementation
bool User::operator==(const User& otherUser) const {
	return (User::username == otherUser.username) && (User::email == otherUser.email);
}
