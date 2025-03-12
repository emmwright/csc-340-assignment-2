#ifndef STORY_
#define STORY_

#include "Post.h"
#include <string>

// Story class inheriting from Post
class Story : public Post {
public:
    Story(const std::string& title, const std::string& mediaURL, int videoLength);

    void displayPost() const override;
   

private:
    int computeTimeToExpiration() const;  // Moved from Post
};

#include "Story.cpp"
#endif // STORY_H
