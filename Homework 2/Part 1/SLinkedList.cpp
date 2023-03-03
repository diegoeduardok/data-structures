//
//  SLinkedList.cpp
//  Homework 2
//
//  Created by Diego Kleiman on 3/23/18.
//  Copyright © 2018 Diego Kleiman. All rights reserved.
//

#include "SLinkedList.hpp"


SLinkedList::SLinkedList(){head = NULL;}

bool SLinkedList::empty() const{return (head == NULL);}

const int& SLinkedList::front() const{
    if(empty()){return NOT_VALUE;}
    return head->value;
}

void SLinkedList::addFront(const int &i){
    Node* v = new Node;
    v -> value = i;
    v->next = head;
    head = v;
}

void SLinkedList::removeFront(){
    if(empty()){return;}
    Node* temp = head;
    temp = head -> next;
    delete head;
    head = temp;
}
