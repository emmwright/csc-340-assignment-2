#include <string>
#include <iostream> 
#include "User.h"
#include "Reel.h"
#include "Story.h"

User::User() : username(""), email(""), password(""), bio(""), profilePicture("") {} 

User::User(const std::string& username, const std::string& email, const std::string& password,  
           const std::string& bio, const std::string& profilePicture) 
    : username(username), email(email), password(password), bio(bio), profilePicture(profilePicture) {} 

bool User::operator==(const User& otherUser) const {
    return (username == otherUser.username) && (email == otherUser.email);
}

std::string User::getUsername() const {
    return username;
}

void User::displayProfile() const { 
    std::cout << "Username: " << username <<
                 "\nEmail: " << email << 
                 "\nPassword: " << password <<
                 "\nBio: " << bio <<
                 "\nProfile Picture: " << profilePicture << std::endl;
}

void User::modifyPassword() {
    std::cout << "modifyPassword() called.\n";
    std::string newPassword;
    std::cout << "Enter new password: ";
    std::cin.ignore(); 
    std::getline(std::cin, newPassword);  
    password = newPassword;  
    std::cout << "Password updated successfully to: " << password << "\n";
}

void User::createPost() {
    std::string title, mediaURL, postType;
    int videoLength;

    std::cout << "Select type of post (Story/Reel):\n";
    while (true) {
    
        std::cin >> postType;
        if (postType == "Story" || postType == "Reel" || postType == "story" || postType == "reel") {
            break;
        } else {
            std::cout << "Invalid. Please enter 'Story' or 'Reel': ";
        }
    }
    std::cout << "Title: ";
    std::cin.ignore(); 
    std::getline(std::cin, title);
    std::cout << "Media URL: ";
    std::getline(std::cin, mediaURL);
    std::cout << "Video Length (in seconds): ";
    while (true) {
        std::cin >> videoLength;
        if (std::cin.fail() || videoLength < 0) {
            std::cout << "Invalid. Enter a positive integer: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    if (postType == "Story" || postType == "story") {
        std::shared_ptr<Post> newStory = std::make_shared<Story>(title, mediaURL, videoLength);
        posts.push_back(newStory);
        std::cout << "Story created";
    } else if (postType == "Reel" || postType == "reel") {
        std::shared_ptr<Post> newReel = std::make_shared<Reel>(title, mediaURL, videoLength);
        posts.push_back(newReel);
        std::cout << "Reel created";
    }
}

void User::displayPosts() {
    std::cout << "Displaying all posts:\n";
    for (const auto& post : posts) {
        post->displayPost();
        std::cout << std::endl;
    }
}

void User::displayKthPost() {
    int k;
    std::cout << "Enter the index of the post to display: ";
    std::cin >> k;
    if (k >= 1 && k <= posts.size()) {
        posts[k-1]->displayPost();
    } else {
        std::cout << "Invalid index. There are only " << posts.size() << " posts.\n";
    }
}

void User::modifyPost() {
    int k;
    std::cout << "Enter index of post to edit: ";
    std::cin >> k;
    if (k >= 1 && k <= posts.size()) {
        Post* postPtr = posts[k-1].get();
           if (dynamic_cast<Reel*>(postPtr)) { 
            std::cout << "You have now added a filter, AR effects and music to your reel.\n";
           } else if (dynamic_cast<Story*>(postPtr)) {
            std::cout << "You have now added a filter, music, stickers and effects to your story.\n";
           }
        } else {
            std::cout << "Invalid index. There are only " << posts.size() << " posts.\n";
            }
           }

void User::editPost() { //assm 3, edit post function to edit title, url or video length
    int k;
     std::cout << "Enter index of post to edit: ";
    std::cin >> k;
    std::cin.ignore(); 
    
    if (k > 1 && k < posts.size()) {
        std::cout << "Invalid index. There are only " << posts.size() << " posts.\n";
        return;
    }
        std::string editType;
        while (true) {
        std::cout << "What do you want to edit: Title, URL, or VideoLength: ";
        std::cin >> editType;
        if (editType == "Title" || editType == "title") {
        std::string newTitle;
        std::cout << "Enter new title: ";
        std::cin.ignore(); 
        std::getline(std::cin, newTitle);
        posts[k-1]->setTitle(newTitle);
        std::cout << "Post updated.\n";
        break;
        }
        else if (editType == "URL" || editType == "url" || editType == "Url") {
        std::string newURL;
        std::cout << "Enter new URL: ";
        std::cin.ignore();
        std::getline(std::cin, newURL);
        posts[k-1]->setMediaURL(newURL);
        std::cout << "Post updated.\n";
        break;
        }
        else if (editType == "VideoLength" || editType == "videolength" || editType == "Video length") {
        int newVideoLength;
        while (true) {
        std::cout << "Enter new video length: ";
        std::cin >> newVideoLength;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid. Enter a positive integer: ";
        } else {
            break;
            }
        }
        posts[k-1]->setVideoLength(newVideoLength);
        std::cout << "Post updated.\n";
        break;
        }
      else {
        std::cout << "Invalid choice, Enter 'Title', 'URL', or 'Video Length': \n";
        }
    }
}


void User::deletePost() { 
    int k;
    std::cout << "Enter index of post to delete: ";
    std::cin >> k;
    if (k >= 1 && k <= posts.size()) {
        posts.erase(posts.begin() + (k-1));
        std::cout << "Post deleted.\n";
    } else {
        std::cout << "Invalid index. There are only " << posts.size() << " posts.\n";
    }
}