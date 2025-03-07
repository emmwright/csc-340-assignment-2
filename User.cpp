// TO DO: #include needed standard libraries and your own libraries here

// TO DO: function implementations

// Operator == overloading implementation
bool User::operator==(const User& otherUser) const {
	return (User::username == otherUser.username) && (User::email == otherUser.email);
}
