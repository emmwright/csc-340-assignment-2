#include "Story.h"
#include <iostream>
#include <chrono>

// Story constructor: initializes title and duration
Story::Story(const std::string& title, const std::string& mediaURL, int videoLength)
    : Post(title, "story_placeholder_url", videoLength) {}

// Display method for Story-specific output
void Story::displayPost() const {
    std::cout << "[Story] Title: " << title << "\nMedia URL: " << mediaURL << "\nVideo Length for story: "
              << videoLength << " seconds\n";

    int timeToExpiration = computeTimeToExpiration();
    if (timeToExpiration > 0) {
        std::cout << timeToExpiration << " hours remaining";
    } else {
        std::cout << "Story is expired";
    }

    // std::cout << std::endl;
}

// When displaying a story, use this to compute expected expiration time: timeToExpiration
// Define this as a private function 
int Story::computeTimeToExpiration() const{
	const int secondsInHour = 3600;
	// 24 hours in seconds
	const int expiresAfter = 24 * secondsInHour; 

	// Get current time
	auto time_now = std::chrono::steady_clock::now();
	// Compute elapsed time since post creation
	std::chrono::duration<double> elapsed_seconds = time_now - time_stamp;
	// time to expiration in hours
	int timeToExpiration = (expiresAfter - elapsed_seconds.count()) / secondsInHour;

	return timeToExpiration;
}