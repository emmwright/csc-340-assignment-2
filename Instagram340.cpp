// TO DO: Implementation of Instagram340 functions
#include <iostream>
#include <string>
#include "Instagram340.h"
#include "User.h"
#include "LinkedBagDS/Node.h"

Instagram340::Instagram340(){
	// TO DO: implement constructor
	users = LinkedBag<User>();
}

Instagram340::~Instagram340(){
	Instagram340::users.clear();
}

void Instagram340::createUser(const std::string& username, const std::string& email, const std::string& password,
                               const std::string& bio, const std::string& profilePicture) {
    User newUser = User(username, email, password, bio, profilePicture); // changed this from User newUser = User();
    users.add(newUser);
}


User Instagram340::getUser(const int& indexK){

	return users.findKthItem(indexK)->getItem();
}