#ifndef POST_
#define POST_

// TO DO: #include all the standard libraries and your own libraries here
#include <string>

// To DO: define the class Post with the necessary functions' prototypes and data fields
class Post {
private:
    std::string title;
    std::chrono::steady_clock::time_point time_stamp;
    int computeTimeToExpiration() const;

public:
    // This is a function that allows you to compare two posts based on their title. 
    // You may directly include it in your class definition. 
    // You don't need to modify it but will have to put it inside your class. 
    // Operator overloading function prototype:
    bool operator==(const Post& otherPost) const;
};

#include "Post.cpp"
#endif