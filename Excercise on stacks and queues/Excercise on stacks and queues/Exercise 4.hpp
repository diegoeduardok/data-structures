//
//  Exercise 4.hpp
//  Excercise on stacks and queues
//
//  Created by Diego Kleiman on 3/24/18.
//  Copyright © 2018 Diego Kleiman. All rights reserved.
//

#ifndef Exercise_4_hpp
#define Exercise_4_hpp

#include <stdio.h>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "Stack.hpp"

using namespace std;

bool CheckPalindrome(const string s){
    long size = s.length();
    int evenness = size%2;
    double steps = floor(size/2);
    Stack<char> test;
    
    for (int i = 0; i<=steps-1; ++i) {cout<<s[i]<<endl;test.push(s[i]);}
    for (int j = steps + evenness; j<size; ++j) {
        cout<<s[j]<<endl;
        if(test.top() == s[j]){test.pop();} else {return false;}
    }
    return test.empty();
}

#endif /* Exercise_4_hpp */
