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
    // Create a new User and populate it with the data
    User newUser = User(username, email, password, bio, profilePicture); // changed this from User newUser = User();
    // Add the new user to the users LinkedBag
    users.add(newUser);
}


User Instagram340::getUser(const int& indexK){
	// TO DO: implement function
	// TODO(emma): Get the kth user in the list of users from the LinkedBag.
	// Node<User>* kthNode = users.findKthItem(indexK);
	// if (kthNode != nullptr){
	// 	return kthNode->getItem();
	// }
	//User newUser = User();
	return users.findKthItem(indexK)->getItem();
}