//
//  ArrayQueue.hpp
//  Excercise on stacks and queues
//
//  Created by Diego Kleiman on 3/24/18.
//  Copyright © 2018 Diego Kleiman. All rights reserved.
//

#ifndef ArrayQueue_hpp
#define ArrayQueue_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class ArrayQueue{
private:
    int* array;
    int size;
    int max_cap;
    int index_front;
    int index_rear;
public:
    ArrayQueue();
    ArrayQueue(int max_size);
    ~ArrayQueue();
    bool empty();
    bool full();
    void enqueue(int i);
    void dequeue();
    void display();
};

#endif /* ArrayQueue_hpp */
