#include "Reel.h"
#include <iostream>

// Reel constructor
Reel::Reel(const std::string& title, const std::string& mediaURL, int videoLength)
    : Post(title, mediaURL, videoLength) {}



// Override display method for Reel-specific output
// void Reel::displayPost() const {
//     std::cout << "[Reel] Title: " << title << "\nMedia URL: " << mediaURL  << "\nVideo Length for reel: " << videoLength << " seconds"
//               << std::endl;
// }

// Getter for reel duration
// int Reel::getDuration() const {
//     return duration;
// }
