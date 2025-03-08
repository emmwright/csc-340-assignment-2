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
				const std::string& bio, const std::string& profilePicture){
	// TO DO: implement function
	User newUser = User();
	// TODO(emma): set attributes (like username, email, etc.) of newUser
	users.add(newUser);
}

User Instagram340::getUser(const int& indexK){
	// TO DO: implement function
	// TODO(emma): Get the kth user in the list of users from the LinkedBag.
	// Node<User>* kthNode = users.findKthItem(indexK);
	// if (kthNode != nullptr){
	// 	return kthNode->getItem();
	// }
	return User();
}