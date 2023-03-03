//
//  Stack.hpp
//  Excercise on stacks and queues
//
//  Created by Diego Kleiman on 3/22/18.
//  Copyright © 2018 Diego Kleiman. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <stdlib.h>
#include <stdexcept>
#include <iostream>

using namespace std;

template <typename E>
class Stack{
    enum {MAX_CAPACITY = 100};
private:
    E* S; //array
    int capacity;
    int t; //number of elements
public:
    Stack(int cap = MAX_CAPACITY) :   S(new E[cap]), capacity(cap), t(-1){} //The colon is to initialize member variables
    int size() const {return t+1;};
    bool empty() const {return t == -1;};
    const E& top() const {
        if(empty()) throw runtime_error("Stack is empty.");
        return S[t];
};
    void push(const E& e){
        if (t>=capacity) throw runtime_error("Stack is full.");
        ++t;
        S[t] = e;
};
    void pop(){
        if(empty()) throw runtime_error("Stack is empty.");
        //cout << S[t] << endl;
        --t;
};
    int find(const E& e){
        if(empty()) throw runtime_error("Stack is empty.");
        for (int i=0; i<=t+1; ++i) {
            if (S[i] == e) {return i;}
        }
        return -1;
};
    void display(){
        if(empty()){return;}
        for (int i=0; i<=t; ++i) {
            cout << S[i];
        }
        cout << endl;
};
    ~Stack(){}//delete[] S;}; 
};
#endif /* Stack_hpp */
