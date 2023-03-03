//
//  DoubleStack.cpp
//  Excercise on stacks and queues
//
//  Created by Diego Kleiman on 3/24/18.
//  Copyright © 2018 Diego Kleiman. All rights reserved.
//

#include "DoubleStack.hpp"

DLList::DLList(){
    size = 0;
    header = new DLNode;
    trailer = new DLNode;
    header->next = trailer;
    trailer->prev = header;
}

DLList::~DLList(){
    if(!empty()){eraseFront();}
    delete header;
    delete trailer;
}

bool DLList::empty(){return (size == 0);}

void DLList::insertFront(Elem e){
    DLNode* n = new DLNode;
    n->value = e;
    n->next = header->next;
    n->prev = header->next->prev;
    header->next->prev = n;
    header->next = n;
    ++size;
}

void DLList::insertBack(Elem e){
    DLNode* n = new DLNode;
    n->value = e;
    n->next = trailer;
    n->prev = trailer->prev;
    trailer->prev->next = n;
    trailer->prev = n;
    ++size;
}

void DLList::eraseFront(){
    if(empty()){return;}
    DLNode* erase = header->next;
    header->next = header->next->next; //Keep an eye out for the value of erase pointer
    header->next->prev = header;
    delete erase;
    --size;
}

void DLList::eraseBack(){
    if(empty()){return;}
    DLNode* erase = trailer->prev;
    trailer->prev = trailer->prev->prev; //Keep an eye out for the value of erase pointer
    trailer->prev->next = trailer;
    delete erase;
    --size;
}

const Elem DLList::front(){
    return header->next->value;
}

const Elem DLList::back(){
    return trailer->prev->value;
}

void DLList::display(){ 
    DLNode* temp = header->next;
    while(temp->next != NULL) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

DoubleStack::DoubleStack(){max_size = 0; size = 0;}

DoubleStack::DoubleStack(int n){max_size = n; size = 0;}

bool DoubleStack::empty(){return size == 0;}

bool DoubleStack::full(){return size == max_size;}

void DoubleStack::pushFront(Elem e){
    if(full()){return;}
    list.insertFront(e);
    ++size;
}

void DoubleStack::pushBack(Elem e){
    if(full()){return;}
    list.insertBack(e);
    ++size;
}

void DoubleStack::popFront(){
    if(empty()){return;}
    list.eraseFront();
}

void DoubleStack::popBack(){
    if(empty()){return;}
    list.eraseBack();
}

void DoubleStack::display(){
    list.display();
}
