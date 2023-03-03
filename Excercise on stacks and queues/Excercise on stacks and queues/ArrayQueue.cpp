//
//  ArrayQueue.cpp
//  Excercise on stacks and queues
//
//  Created by Diego Kleiman on 3/24/18.
//  Copyright © 2018 Diego Kleiman. All rights reserved.
//

#include "ArrayQueue.hpp"

ArrayQueue::ArrayQueue(){
    array = NULL;
    size = -1;
    max_cap = 0;
    index_front = 0;
    index_rear = 0;
}

ArrayQueue::ArrayQueue(int max_size){
    max_cap = max_size-1;
    array = new int[max_cap];
    size = -1;
    index_front = 0;
    index_rear = 0;
}

ArrayQueue::~ArrayQueue(){delete[] array;}

bool ArrayQueue::empty(){return size == -1;}

bool ArrayQueue::full(){return size == max_cap;}

void ArrayQueue::enqueue(int i){
    if(full()){return;}
    ++size;
    if(index_rear == max_cap+1){index_rear = 1;}else{++index_rear;}
    array[index_rear-1] = i;
    }

void ArrayQueue::dequeue(){
    if(empty()){return;}
     --size;
    cout<<array[index_front]<<endl;
    array[index_front] = NULL;
    if(index_front == max_cap+1){index_front = 0;}else{++index_front;}
}

void ArrayQueue::display(){
    if(empty()){return;}
    for (int i = 0; i<=size; ++i) {
        int index = (index_front+i)%(max_cap+1);
        cout << array[index] << " ";
    }
    cout << endl;
}

