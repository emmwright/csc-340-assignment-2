
#include "Post.h"
#include <chrono>
#include <string>
#include <iostream>

Post::Post() : time_stamp(std::chrono::steady_clock::now()) {}

Post::Post(const std::string& title, const std::string& mediaURL, int videoLength)
    : title(title), mediaURL(mediaURL), videoLength(videoLength), time_stamp(std::chrono::steady_clock::now()) {}

bool Post::operator==(const Post& otherPost) const {
	return Post::title == otherPost.title;
}


