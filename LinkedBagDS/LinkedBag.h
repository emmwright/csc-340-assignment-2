//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT bag: Link-based implementation.
	 @file LinkedBag.h 
	 Listing 4-3 */
#ifndef LINKED_BAG_
#define LINKED_BAG_

#include "BagInterface.h"
#include "Node.h"
#include <memory>  // For std::shared_ptr

template<class ItemType>
class LinkedBag : public BagInterface<ItemType>
{
private:
	std::shared_ptr<Node<ItemType>> headPtr; //assm 3
	int itemCount;			  // current count of bag items
	std::shared_ptr<Node<ItemType>> getPointerTo(const ItemType& target) const;

public:
	LinkedBag();
	LinkedBag(const LinkedBag<ItemType>& aBag); // copy constructor
	virtual ~LinkedBag();						// destructor should be virtual

	LinkedBag<ItemType>& operator=(const LinkedBag<ItemType>& aBag); //assm 3, adding this for big 3 overloaded assignment operator

	// Assignment 2 functions -------------------------------------------
	bool append(const ItemType& newEntry);
	
	std::shared_ptr<Node<ItemType>> findKthItem(const int& indexK) const; // assm 3
	// ------------------------------------------------------------------
	
	int getCurrentSize() const;
	bool isEmpty() const;
	bool add(const ItemType& newEntry);
	bool remove(const ItemType& anEntry);
	void clear();
	bool contains(const ItemType& anEntry) const;
	int getFrequencyOf(const ItemType& anEntry) const;
	std::vector<ItemType> toVector() const;

}; // end LinkedBag

#include "LinkedBag.cpp"
#endif