//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT bag: Link-based implementation.
	 @file LinkedBag.cpp */

#include "LinkedBag.h"
#include "Node.h"
#include <cstddef>


template<class ItemType>
std::shared_ptr<Node<ItemType>> LinkedBag<ItemType>::findKthItem(const int& indexK) const { // assm 3
	
	if (indexK < 0 || indexK >= itemCount) {
		return nullptr; // if indexK is invalid, return null
	}
	auto curPtr = headPtr; 
	int counter = 0;
	while (curPtr != nullptr && counter < indexK) { //if current is not equal to null and counter is less than k
		curPtr = curPtr->getNext(); //move to the next node
		counter++;
	}
	return curPtr; //return the current/kth node
}

// ------------------------------------------------------------------

template<class ItemType>
LinkedBag<ItemType>::LinkedBag() : headPtr(nullptr), itemCount(0){}  // end default constructor

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& aBag){ //big 3, creates a deep copy of another LinkedBag
	itemCount = aBag.itemCount;
	std::shared_ptr<Node<ItemType>> origChainPtr = aBag.headPtr;  // assm 3
	
	if (origChainPtr == nullptr)
		headPtr = nullptr;  // Original bag is empty
	else{
		headPtr = std::make_shared<Node<ItemType>>(origChainPtr->getItem()); // assm 3 shared pointer
		//copy remaining nodes
		std::shared_ptr<Node<ItemType>> newChainPtr = headPtr;
		origChainPtr = origChainPtr->getNext();

		while (origChainPtr != nullptr){
			// get next item from original chain
			ItemType nextItem = origChainPtr->getItem();
				  
			// create a new node containing the next item
			auto newNodePtr = std::make_shared<Node<ItemType>>(nextItem); // assm 3

			// link new node to end of new chain
			newChainPtr->setNext(newNodePtr);
			
			// next node pointer to new last node
			newChainPtr = newChainPtr->getNext();

			// next node in original chain pointer
			origChainPtr = origChainPtr->getNext();
		}  // end while
		
		//newChainPtr->setNext(nullptr); //shared pointer will already put next pointer to null pointer
	}  // end if
}  // end copy constructor


template<class ItemType> //big 3, overloaded assignment operator for big 3
LinkedBag<ItemType>& LinkedBag<ItemType>::operator=(const LinkedBag<ItemType> &aBag) {
	if (this != &aBag) { //to prevent self-assignment
		clear(); //deletes all nodes
	
		itemCount = aBag.itemCount; //copy itemCount
		auto origChainPtr = aBag.headPtr; //copy head pointer
		if (origChainPtr == nullptr) {
			headPtr = nullptr;
		} else {
			headPtr = std::make_shared<Node<ItemType>>(origChainPtr->getItem()); //copy first node
			auto newChainPtr = headPtr; //copy new chain pointer
			origChainPtr = origChainPtr->getNext(); //move to next node in original chain

			while (origChainPtr != nullptr) { 
				auto newNodePtr = std::make_shared<Node<ItemType>>(origChainPtr->getItem()); //copy remaining nodes
				newChainPtr->setNext(newNodePtr); //link new node to end of new chain
				newChainPtr = newNodePtr; //move to last node in new chain
				origChainPtr = origChainPtr->getNext(); //move to next node in original chain
			}
		}
	}
	return *this;
}





template<class ItemType>
LinkedBag<ItemType>::~LinkedBag(){
	clear(); //big 3 implementation, clear deletes all nodes.
}  // end destructor


template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() const{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const{
	return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool LinkedBag<ItemType>::add(const ItemType& newEntry){
	auto nextNodePtr = std::make_shared<Node<ItemType>>(newEntry); //assm 3
	
	nextNodePtr->setNext(headPtr);  // new node points to chain
	headPtr = nextNodePtr;			// new node is now first node
	itemCount++;
	
	return true;
}  // end add

template<class ItemType>
std::vector<ItemType> LinkedBag<ItemType>::toVector() const{
	std::vector<ItemType> bagContents;
	std::shared_ptr<Node<ItemType>> curPtr = headPtr; // assm 3
	int counter = 0;
	while ((curPtr != nullptr) && (counter < itemCount)){
		bagContents.push_back(curPtr->getItem());
		curPtr = curPtr->getNext();
		counter++;
	}  // end while
	
	return bagContents;
}  // end toVector

template<class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& anEntry){
	auto entryNodePtr = getPointerTo(anEntry); //assm 3

	bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);
	if (canRemoveItem){

		if (headPtr == entryNodePtr) {
			headPtr = headPtr->getNext(); //if first node is node to be removed, move head node to next
		} else { 
		auto prevNodePtr = headPtr;

		while (prevNodePtr->getNext() != entryNodePtr) {
			prevNodePtr = prevNodePtr->getNext();
		}
		prevNodePtr->setNext(entryNodePtr->getNext()); // link previous node to the next node of the entry node
		}
		itemCount--;
 	}

	return canRemoveItem;
	}
		

template<class ItemType>
void LinkedBag<ItemType>::clear(){
	headPtr.reset(); //assm 3, deletes all nodes
	itemCount = 0;
}  // end clear

template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const{
	int frequency = 0;
	int counter = 0;
	Node<ItemType>* curPtr = headPtr;
	while ((curPtr != nullptr) && (counter < itemCount)){
		if (anEntry == curPtr->getItem()){
			frequency++;
		} // end if
		
		counter++;
		curPtr = curPtr->getNext();
	} // end while
	
	return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const{
	return (getPointerTo(anEntry) != nullptr);
}  // end contains



// private
// Returns either a pointer to the node containing a given entry 
// or the null pointer if the entry is not in the bag.
template<class ItemType>
std::shared_ptr<Node<ItemType>> LinkedBag<ItemType>::getPointerTo(const ItemType& anEntry) const {

	bool found = false;
	auto curPtr = headPtr;
	
	while (!found && (curPtr != nullptr)){
		if (anEntry == curPtr->getItem())
			found = true;
		else
			curPtr = curPtr->getNext();
	} // end while
	
	return curPtr;
} // end getPointerTo


