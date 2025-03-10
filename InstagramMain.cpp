#include <iostream> 
#include <string>

// TO DO: #include any other libraries you need
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
//		cout << "\n Hi, "<< user.getUsername() <<", what would you like to do:\n"
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
				// TO DO: display user's profile information
				//      : e.g. user.displayProfile();
				user.displayProfile();
			 	break;
			}
			case 2: {
				// TO DO: ask for new password and update user's password
				user.modifyPassword();
				break;
			}
			case 3: {
				// TO DO: ask user to choose between Reel and Story, ask them to input post details:
				//        (title, media URL, video length in seconds)
				//        Your program should set the time stamp to current time (code provided in Post.cpp) 
				// then create the post and add it to the user's posts
				user.createPost();
				break;
			}
			case 4:{
				// TO DO: display all user's posts
				//        You may re-use code from class demo
				user.displayPosts();
				break;
			}
			case 5: {
				// TO DO: ask the user for a value k
				// Find the Kth post, if k > Linked Bag size, 
				//    return an error message that includes the size of the Linked Bag
				user.displayKthPost();
				break;
			}
			case 6: {
				// TO DO: ask the user for the index of the post they want to modify and the new title
				// Find the post, then update the title. 
				// If index > Linked Bag size, 
				//    return an error message that includes the size of the Linked Bag
				user.modifyPost();
				break;
			}
			case 7: {
				// TO DO: ask the user for the index of the post they want to delete 
				// Find the post, then remove it from the list. 
				// If index > LinkedBag size, 
				//    return an error message that includes the size of the Linked Bag
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
	// Instantiating the program using the default constructor
	// With this implementation, the application will only have one user
	Instagram340 instagram; 

	cout << "\n Welcome to Instagram340:" << endl;
	// TO DO: Ask the user to enter their information 
	//        Instantiate a new User object
	
	std::string username = "Emma";
	std::string email = "emma@cs.com";
	std::string password = "123456";
	std::string bio = "I love coding!";
	std::string profilePicture = "https://www.cs.com/Emma.jpg";

	// call instagram createUser function 
	// replace /*...*/ with the right parameters
	instagram.createUser(username, email, password, bio, profilePicture);

	// Retrieve the user 
	User currentUser = instagram.getUser(0);
	displayUserMenu(currentUser);
				
	return 0;
}