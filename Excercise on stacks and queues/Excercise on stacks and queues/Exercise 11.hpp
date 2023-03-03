//
//  Exercise 11.hpp
//  Excercise on stacks and queues
//
//  Created by Diego Kleiman on 3/25/18.
//  Copyright © 2018 Diego Kleiman. All rights reserved.
//

#ifndef Exercise_11_hpp
#define Exercise_11_hpp

#include <stdio.h>
#include "Stack.hpp"


void minToBottom(Stack<int> input){
    int fix_size = input.size();
    Stack<int> tempStack(fix_size);
    int counter = 0;
    int minimum = 0;
    for (int i = 0; i<fix_size; ++i) {
        if(i==0){
            minimum = input.top();
            ++counter;
            tempStack.push(input.top());
            input.pop();
        }
        else if(input.top() == minimum){
            ++counter;
            tempStack.push(input.top());
            input.pop();
        }
        else if(input.top() < minimum){
            counter = 1;
            minimum = input.top();
            tempStack.push(input.top());
            input.pop();
        }
        else if (input.top() > minimum){
            tempStack.push(input.top());
            input.pop();
        }
    }
    for (int j = 1; j<=counter; ++j) {input.push(minimum);}
    for (int k = 0; k<fix_size; ++k) {
        if(tempStack.top()!=minimum){input.push(tempStack.top()); tempStack.pop();}
        else{tempStack.pop();}
    }
}

#endif /* Exercise_11_hpp */
