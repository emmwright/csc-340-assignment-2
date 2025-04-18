#ifndef USER_
#define USER_

#include <string>
#include "Post.h"
#include <vector>
#include <memory>   // For std::shared_ptr

class User {
private:
    std::string username;
    std::string email;
    std::string password; 
    std::string bio;  
    std::string profilePicture; 
    std::vector<std::shared_ptr<Post>> posts;

public:
    bool operator==(const User& otherUser) const;
    std::string getUsername() const;
   
    void displayProfile() const; 
    void modifyPassword(); 
    void createPost(); 
    void displayPosts();
    void displayKthPost();
    void modifyPost();
    void deletePost();
    void editPost();

    User(); 
    User(const std::string& username, const std::string& email, const std::string& password,
         const std::string& bio, const std::string& profilePicture); 

    User(const std::string& username, const std::string& email); 

};

#include "User.cpp"
#endif
