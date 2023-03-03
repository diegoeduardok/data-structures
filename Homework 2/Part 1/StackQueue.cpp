//
//  StackQueue.cpp
//  Homework 2
//
//  Created by Diego Kleiman on 3/23/18.
//  Copyright © 2018 Diego Kleiman. All rights reserved.
//

#include "StackQueue.hpp"

//Definitions for Stack

int Stack::size() const {return num;}

bool Stack::empty() const {return (num == -1);}

const int& Stack::top() const {return S.front();}

void Stack::push(const int& i){S.addFront(i);++num;}

int Stack::pop(){
    if(empty()){return NOT_VALUE;}
    int temp = S.front();
    S.removeFront();
    --num;
    return temp;
}

//Definitions for StackQueue

void StackQueue::enqueue(const int& i){
    input.push(i);
    ++num;
}

int StackQueue::dequeue(){
    if(output.empty()){ //If output stack is empty, fill up with elements from input (order will be reversed)
        if(input.empty()){return NOT_VALUE;} //If input is also empty, then NOT_VALUE will be returned
        while(not input.empty()) {
            output.push(input.pop()); //Fill up output stack until input stack is empty
        }
    }
    --num;
    return output.pop();
}

const int& StackQueue::front() {
    if(output.empty()){ //If output stack is empty, fill up with elements from input (order will be reversed)
        if(input.empty()){return NOT_VALUE;} //If input is also empty, then NOT_VALUE will be returned
        while(!input.empty()) {
            output.push(input.pop()); //Fill up output stack until input stack is empty
        }
    }
    return output.top(); //Return front of the queue but keep element
}

int StackQueue::size() const {
    return num+1;
}

bool StackQueue::empty() const {
    return (input.empty() && output.empty()); //Queue is emtpy if both stacks are empty
}
