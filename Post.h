#ifndef POST_
#define POST_

// TO DO: #include all the standard libraries and your own libraries here
#include <string>
#include <chrono>

// To DO: define the class Post with the necessary functions' prototypes and data fields
class Post {
private:
    std::string title;
    std::chrono::steady_clock::time_point time_stamp;
    std::string mediaURL;
    int computeTimeToExpiration() const;
    int videoLength;


public:
    Post();
    Post(const std::string& title, const std::string& mediaURL, int videoLength);
    bool operator==(const Post& otherPost) const;

    void displayPost() const;
    void setTitle(const std::string & newTitle) {
        title = newTitle;
    }
};

#include "Post.cpp"
#endif