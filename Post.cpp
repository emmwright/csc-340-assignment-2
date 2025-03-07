// TO DO: #include all the standard libraries and your own libraries here
#include <chrono>


// TO DO: function implementations



// When creating a post, you may use this code to set time stamp
auto time_stamp = std::chrono::steady_clock::now();


// ------------------------------------------------------------------------------
// Operator overloading implementation
bool Post::operator==(const Post& otherPost) const {
	return Post::title == otherPost.title;
}

// When displaying a story, use this to compute expected expiration time: timeToExpiration
// Define this as a private function 
int Post::computeTimeToExpiration() const{
	const int secondsInHour = 3600;
	// 24 hours in seconds
	const int expiresAfter = 24 * secondsInHour; 

	// Get current time
	auto time_now = std::chrono::steady_clock::now();
	// Compute elapsed time since post creation
	std::chrono::duration<double> elapsed_seconds = time_now - Post::time_stamp;
	// time to expiration in hours
	int timeToExpiration = (expiresAfter - elapsed_seconds.count()) / secondsInHour;

	return timeToExpiration;
}


