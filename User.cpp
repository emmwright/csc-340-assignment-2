// TO DO: #include needed standard libraries and your own libraries here
#include <string>
#include <iostream> 
#include "User.h"

User::User() : username(""), email(""), password(""), bio(""), profilePicture("") {} 

User::User(const std::string& username, const std::string& email, const std::string& password,  
           const std::string& bio, const std::string& profilePicture) 
    : username(username), email(email), password(password), bio(bio), profilePicture(profilePicture) {} 

bool User::operator==(const User& otherUser) const {
    return (username == otherUser.username) && (email == otherUser.email);
}

//Getter 
std::string User::getUsername() const {
    return username;
}

void User::displayProfile() const { 
    std::cout << "Username: " << username <<
                 "\nEmail: " << email << 
                 "\nPassword: " << password <<
                 "\nBio: " << bio <<
                 "\nProfile Picture: " << profilePicture << std::endl;
}

void User::modifyPassword() {
    std::cout << "modifyPassword() called.\n";
    std::string newPassword;
    std::cout << "Enter new password: ";
    std::cin.ignore(); 
    std::getline(std::cin, newPassword);  
    password = newPassword;  
    std::cout << "Password updated successfully to: " << password << "\n";
}

void User::createPost() {
    std::string title, mediaURL, postType;
    int videoLength;
    std::cout << "Select type of post:\n";
    std::cin >> postType;
    std::cout << "Title: ";
    std::cin.ignore(); 
    std::getline(std::cin, title);
    std::cout << "Media URL: ";
    std::getline(std::cin, mediaURL);
    std::cout << "Video Length (in seconds): ";
    std::cin >> videoLength;
    posts.emplace_back(title, mediaURL, videoLength);
    std::cout << (postType == "Story" ? "Story" : "Reel") << " Created successfully.\n";
    
}

void User::displayPosts() {
    std::cout << "Displaying all posts:\n";
    for (const auto& post : posts) {
        post.displayPost();
        std::cout << std::endl;
    }
}

void User::displayKthPost() {
    int k;
    std::cout << "Enter the index of the post to display: ";
    std::cin >> k;
    if (k >= 1 && k <= posts.size()) {
        posts[k-1].displayPost();
    } else {
        std::cout << "Invalid index. There are only " << posts.size() << " posts.\n";
    }
}

void User::modifyPost() {
    int k;
    std::cout << "Enter index of post to edit: ";
    std::cin >> k;
    if (k >= 1 && k <= posts.size()) {
        std::string newTitle;
        std::cout << "Enter new title: ";
        std::cin.ignore(); 
        std::getline(std::cin, newTitle);
        posts[k-1].setTitle(newTitle);
        std::cout << "Post updated.\n";
    } else {
        std::cout << "Invalid index. There are only " << posts.size() << " posts.\n";
    }
}

void User::deletePost() { 
    int k;
    std::cout << "Enter index of post to delete: ";
    std::cin >> k;
    if (k >= 1 && k <= posts.size()) {
        posts.erase(posts.begin() + (k-1));
        std::cout << "Post deleted.\n";
    } else {
        std::cout << "Invalid index. There are only " << posts.size() << " posts.\n";
    }
}