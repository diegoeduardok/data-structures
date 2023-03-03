//
//  SLinkedList.hpp
//  Homework 2
//
//  Created by Diego Kleiman on 3/23/18.
//  Copyright © 2018 Diego Kleiman. All rights reserved.
//

#ifndef SLinkedList_hpp
#define SLinkedList_hpp

#include <stdio.h>

const int NOT_VALUE = -1;

//For the sake of this exercise, the nodes will contain integer values
class Node{
    friend class SLinkedList;
private:
    int value;
    Node* next;
};

class SLinkedList{
private:
    Node* head;
public:
    SLinkedList(); //Constructor
    ~SLinkedList(){while(!empty()){removeFront();}}; //Destructor
    bool empty() const; //Returns true if function is empty
    const int& front() const; //Returns first element of the list
    void addFront(const int& i); //Adds element to the front of the list
    void removeFront(); //Removes first element of the list
};

#endif /* SLinkedList_hpp */
