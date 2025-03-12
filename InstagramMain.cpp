#include <iostream> 
#include <string>
#include "Instagram340.h"

using namespace std;

/** 
 * 
 * Displays the application's main menu
 * pre create a new object of type User
 * @param user object to interact with
 * 
 * */
void displayUserMenu(User& user){
	int userChoice = 0;
	do {
		cout << "\n Hi, "<< user.getUsername() <<", what would you like to do:\n";
		cout << "\n Hi, what would you like to do:\n"

		<< "1. Display Profile\n"
		<< "2. Modify Password\n"
		<< "3. Create Post\n"
		<< "4. Display All Posts\n"
		<< "5. Display Kth Post\n"
		<< "6. Modify Post\n"
		<< "7. Delete Post\n"
		<< "0. Logout\n"
		<< "Choice: ";
		cin >> userChoice;

		switch (userChoice) {
			case 1:{
				user.displayProfile();
			 	break;
			}
			case 2: {
				user.modifyPassword();
				break;
			}
			case 3: {
				user.createPost();
				break;
			}
			case 4:{
				user.displayPosts();
				break;
			}
			case 5: {
				user.displayKthPost();
				break;
			}
			case 6: {
				user.modifyPost();
				break;
			}
			case 7: {
				user.deletePost();
				break;
			}
			case 8:{
				
			}
			case 0: {
				cout << "Logging you out." << endl;
				break;
			}
			default:
				cout << "Invalid choice. Please try again." << endl;
		}

	} while (userChoice != 0);
}


int main(){

	Instagram340 instagram; 

	cout << "\n Welcome to Instagram340:" << endl;

	
	std::string username = "Emma";
	std::string email = "emma@cs.com";
	std::string password = "123456";
	std::string bio = "I love coding!";
	std::string profilePicture = "https://www.cs.com/Emma.jpg";

	instagram.createUser(username, email, password, bio, profilePicture);

	// Retrieve the user 
	User currentUser = instagram.getUser(0);
	displayUserMenu(currentUser);
				
	return 0;
}