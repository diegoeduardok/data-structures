//
//  Dequeue.hpp
//  Excercise on stacks and queues
//
//  Created by Diego Kleiman on 3/25/18.
//  Copyright © 2018 Diego Kleiman. All rights reserved.
//

#ifndef Dequeue_hpp
#define Dequeue_hpp

#include <stdio.h>
#include "DoubleStack.hpp"

class Dequeue{
private:
    DLList list;
    int n; //size
public:
    Dequeue();
    ~Dequeue(){} //The destructor of the list will deallocate the memory
    int size();
    bool empty();
    const string& front();
    const string& back();
    void insertFront(string s);
    void insertBack(string s);
    void removeFront();
    void removeBack();
    void display();
};
#endif /* Dequeue_hpp */
