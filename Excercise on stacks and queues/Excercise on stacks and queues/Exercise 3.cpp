//
//  Exercise 3.cpp
//  Excercise on stacks and queues
//
//  Created by Diego Kleiman on 3/24/18.
//  Copyright © 2018 Diego Kleiman. All rights reserved.
//

#include "Exercise 3.hpp"

bool isComplement(char c, char d){
    if(c == '}' && d == '{') {return true;}
    else if(c == ']' && d == '[') {return true;}
    else if(c == ')' && d == '(') {return true;}
    else {return false;}
}

bool CheckParentheses(const string s){
    long size = s.length();
    if(size%2!=0) return false; //It must be an even number of parentheses
    Stack<char> test;
    for (int i = 0; i<=size; ++i) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {test.push(s[i]);}
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']'){
            if(test.empty()) {return false;} //Ending parenthesis without pair
            if(!isComplement(s[i], test.top())) {return false;} else {test.pop();}
        }
    }
    return test.empty();
    
}
