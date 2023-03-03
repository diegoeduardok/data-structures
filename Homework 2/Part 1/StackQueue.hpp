//
//  StackQueue.hpp
//  Homework 2
//
//  Created by Diego Kleiman on 3/23/18.
//  Copyright © 2018 Diego Kleiman. All rights reserved.
//

#ifndef StackQueue_hpp
#define StackQueue_hpp

#include <stdio.h>
#include "SLinkedList.hpp"

class Stack{
private:
    SLinkedList S;
    int num; //number of elements
public:
    Stack(){num = -1;} //Constructor
    ~Stack(){}; //Destructor
    int size() const; //Returns the number of elements
    bool empty() const; //Returns true if stack is empty
    const int& top() const; //Look at top of the stack (last element added)
    void push(const int& i); //Insert element in the stack
    int pop(); //Remove last element inserted
};

class StackQueue{
private:
    Stack input;
    Stack output;
    int num; //number of elements
public:
    StackQueue(){num = -1;} //Constructor
    ~StackQueue(){}; //Destructor
    void enqueue(const int& i); //Adds element to queue
    int dequeue(); //Removes (and returns) oldest element in the queue (first in-first out)
    const int& front(); //Looks at front of the queue (oldest element)
    int size() const; //Number of elements in the queue
    bool empty() const; //Checks if queue is empty (both stacks empty)
};
#endif /* StackQueue_hpp */
