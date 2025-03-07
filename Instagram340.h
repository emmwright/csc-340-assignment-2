#include "LinkedBagDS/LinkedBag.h"
// TO DO include necessary libraries

 

// This class only contains a list of users
// It should allow clients to add users and retrieve a user from the list
class Instagram340 {
	private:
		LinkedBag<User> users;

	public:
		Instagram340();
		~Instagram340();

		void createUser(const std::string& username, const std::string& email, const std::string& password,
						const std::string& bio, const std::string& profilePicture);

		User getUser(const int& indexK);
};