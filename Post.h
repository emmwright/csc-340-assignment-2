#ifndef POST_
#define POST_

// TO DO: #include all the standard libraries and your own libraries here
#include <string>
#include <chrono>
#include <iostream>

// To DO: define the class Post with the necessary functions' prototypes and data fields
class Post {
protected:
    std::string title;
    std::chrono::steady_clock::time_point time_stamp;
    std::string mediaURL;
   // int computeTimeToExpiration() const;
    int videoLength;


public:
    // Constructor and other member functions
    Post();
    Post(const std::string& title, const std::string& mediaURL, int videoLength);
    bool operator==(const Post& otherPost) const;

    // Virtual function to allow overriding in derived classes
    virtual void displayPost() const; //{  // Correct location for 'virtual'
    //     std::cout << "Title: " << title << "\nMedia URL: " << mediaURL 
    //               << "\nVideo Length: " << videoLength << " seconds";
    // }

    void setTitle(const std::string & newTitle) {
        title = newTitle;
    }
};

#include "Post.cpp"

#endif