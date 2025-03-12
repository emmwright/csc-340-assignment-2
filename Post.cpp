// TO DO: #include all the standard libraries and your own libraries here
#include "Post.h"
#include <chrono>
#include <string>
#include <iostream>

// TO DO: function implementations
Post::Post() : time_stamp(std::chrono::steady_clock::now()) {}

Post::Post(const std::string& title, const std::string& mediaURL, int videoLength)
    : title(title), mediaURL(mediaURL), videoLength(videoLength), time_stamp(std::chrono::steady_clock::now()) {}

// When creating a post, you may use this code to set time stamp
// auto time_stamp = std::chrono::steady_clock::now(); // moved to Post()


bool Post::operator==(const Post& otherPost) const {
	return Post::title == otherPost.title;
}


void Post::displayPost() const { 
	std::cout << "Title: " << title << "\nMedia URL: " << mediaURL <<
	 "\nVideo Length: " << videoLength << " seconds";
}