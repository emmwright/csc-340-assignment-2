#ifndef INSTAGRAM340_
#define INSTAGRAM340_

#include <vector>
#include <memory>
#include "LinkedBagDS/LinkedBag.h"
#include "User.h"
 

// This class only contains a list of users
// It should allow clients to add users and retrieve a user from the list
class Instagram340 {
	private:
		std::vector<std::shared_ptr<User>> users; //assm 3

	public:
		Instagram340();
		~Instagram340();

		void createUser(const std::string& username, const std::string& email, const std::string& password,
						const std::string& bio, const std::string& profilePicture);

		User getUser(const int& indexK);
};

#include "Instagram340.cpp"
#endif