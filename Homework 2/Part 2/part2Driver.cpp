//
//  main.cpp
//  Part 2
//
//  Created by Diego Kleiman on 3/23/18.
//  Copyright © 2018 Diego Kleiman. All rights reserved.
//

#include <iostream>
#include "DLCirList.hpp"

int main() {
    DLCirList example;
    example.insertFront("D");
    example.insertFront("C");
    example.insertFront("B");
    example.insertFront("A");
    example.display();
    

    cout << example.eatMissionary(3) << endl;
    example.display();
    cout << example.eatMissionary(6) << endl;
    example.display();
    cout << example.eatMissionary(1) << endl;
    example.display();
    cout << example.eatMissionary(1) << endl;
    return 0;
}
