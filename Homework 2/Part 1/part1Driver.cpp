//
//  main.cpp
//  Homework 2
//
//  Created by Diego Kleiman on 3/23/18.
//  Copyright © 2018 Diego Kleiman. All rights reserved.
//

#include <iostream>
#include "StackQueue.hpp"
#include "SLinkedList.hpp"

using namespace std;

int main() {
    StackQueue example;
    example.enqueue(1); example.enqueue(2); example.enqueue(3);
    cout << "Size should be 3: " << example.size() << endl;
    cout << example.front() << " = " << example.dequeue() << endl;
    cout << "Size should be 2: " << example.size() << endl;
    cout << example.front() << " = " << example.dequeue() << endl;
    cout << "Size should be 1: " << example.size() << endl;
    example.enqueue(4);
    if(!example.empty()){cout << "Queue is NOT empty." << endl;}
    cout << "Size should be 2: " << example.size() << endl;
    cout << example.front() << " = " << example.dequeue() << endl;
    cout << "Size should be 1: " << example.size() << endl;
    cout << example.front() << " = " << example.dequeue() << endl;
    cout << "Size should be 0: " << example.size() << endl;
    if(example.empty()){cout << "Queue is empty." << endl;}
    return 0;
}
