#ifndef POST_
#define POST_


#include <string>
#include <chrono>
#include <iostream>


class Post {
protected:
    std::string title;
    std::chrono::steady_clock::time_point time_stamp;
    std::string mediaURL;
    int videoLength;


public:
    Post();
    Post(const std::string& title, const std::string& mediaURL, int videoLength);
    bool operator==(const Post& otherPost) const;

    virtual void displayPost() const { 
	    std::cout << "Title: " << title << "\nMedia URL: " << mediaURL <<
	     "\nVideo Length: " << videoLength << " seconds";
    }

    void setTitle(const std::string & newTitle) {
        title = newTitle;
    }

    virtual ~Post() {}
};

#include "Post.cpp"
#endif