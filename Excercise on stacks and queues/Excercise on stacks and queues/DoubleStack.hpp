//
//  DoubleStack.hpp
//  Excercise on stacks and queues
//
//  Created by Diego Kleiman on 3/24/18.
//  Copyright © 2018 Diego Kleiman. All rights reserved.
//

#ifndef DoubleStack_hpp
#define DoubleStack_hpp

#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

typedef string Elem;

class DLNode{
    friend class DLList;
private:
    DLNode* next;
    DLNode* prev;
    Elem value;
public:
    DLNode(){next = NULL; prev = NULL; value = "";}
};
class DLList{
    friend class DoubleStack;
private:
    DLNode* header;
    DLNode* trailer;
    int size;
public:
    DLList();
    ~DLList();
    bool empty();
    void insertFront(Elem e);
    void insertBack(Elem e);
    void eraseFront();
    void eraseBack();
    const Elem front();
    const Elem back();
    void display();
};

class DoubleStack{
private:
    DLList list;
    int max_size; //Predetermined size passed to constructor
    int size;
public:
    DoubleStack();
    DoubleStack(int n); //Constructor requiring size
    ~DoubleStack(){} //The destructor of the list should deallocate the memory
    bool empty();
    bool full();
    void pushFront(Elem e);
    void pushBack(Elem e);
    void popFront();
    void popBack();
    void display();
};
#endif /* DoubleStack_hpp */
