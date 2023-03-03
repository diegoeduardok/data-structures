//
//  Exercise 2.cpp
//  Excercise on stacks and queues
//
//  Created by Diego Kleiman on 3/24/18.
//  Copyright © 2018 Diego Kleiman. All rights reserved.
//

#include "Exercise 2.hpp"

Stack<char> ReverseStr(const string s){
    long len = s.length();
    Stack<char> input;
    Stack<char> output;
    for (int i = 0; i<len; ++i) {input.push(s[i]); }
    for (int i = 0; i<len; ++i) {output.push(input.top()); input.pop();}
    return output;
}
