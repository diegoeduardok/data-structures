//
//  Dequeue.cpp
//  Excercise on stacks and queues
//
//  Created by Diego Kleiman on 3/25/18.
//  Copyright © 2018 Diego Kleiman. All rights reserved.
//

#include "Dequeue.hpp"

Dequeue::Dequeue(){n = 0;}

int Dequeue::size(){return n;}

bool Dequeue::empty(){return n==0;}

const string& Dequeue::front(){static string output = list.front(); return output;}

const string& Dequeue::back(){static string output = list.back(); return output;}

void Dequeue::insertFront(string s){list.insertFront(s); ++n;}
void Dequeue::insertBack(string s){list.insertBack(s); ++n;}
void Dequeue::removeFront(){list.eraseFront(); --n;}
void Dequeue::removeBack(){list.eraseBack(); --n;}
void Dequeue::display(){list.display();}
