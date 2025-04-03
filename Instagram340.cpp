// TO DO: Implementation of Instagram340 functions
#include <iostream>
#include <string>
#include "Instagram340.h"
#include "User.h"
#include "LinkedBagDS/Node.h"

Instagram340::Instagram340(){
	users = std::vector<std::shared_ptr<User>>(); //assm3
}

Instagram340::~Instagram340(){
	Instagram340::users.clear();
}

void Instagram340::createUser(const std::string& username, const std::string& email, const std::string& password,
                               const std::string& bio, const std::string& profilePicture) {
	//assm 3
	std::shared_ptr<User> newUser = std::make_shared<User>(username, email, password, bio, profilePicture);
	users.push_back(newUser);
}


User Instagram340::getUser(const int& indexK){

	return *(users[indexK]);
}