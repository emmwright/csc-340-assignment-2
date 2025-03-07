// TO DO: #include all the standard libraries and your own libraries here

// To DO: define the class Post with the necessary functions' prototypes and data fields

// This is a function that allows you to compare two posts based on their title. 
// You may directly include it in your class definition. 
// You don't need to modify it but will have to put it inside your class. 
// Operator overloading function prototype:
bool operator==(const Post& otherPost) const; 

// This is a helper function -- it should be private.
int computeTimeToExpiration() const;
