#ifndef REEL_
#define REEL_

#include "Post.h"

// Reel class inheriting from Post
// declare the methods here
class Reel : public Post {
public:
    // Constructor
    Reel(const std::string& title, const std::string& mediaURL, int videoLength);
    void displayPost() const override {
         std::cout << "[Reel] Title: " << title << "\nMedia URL: " << mediaURL << "\nVideo Length: " << videoLength << " seconds\n";
}

};

#include "Reel.cpp"
#endif 
