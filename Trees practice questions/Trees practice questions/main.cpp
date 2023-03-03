//
//  main.cpp
//  Trees practice questions
//
//  Created by Diego Kleiman on 4/7/18.
//  Copyright © 2018 Diego Kleiman. All rights reserved.
//

#include <iostream>
#include "BSTree.hpp"

int main() {
    BSTree example;
    example.addElement(4);
    example.addElement(5);
    example.addElement(3);
    example.addElement(2);
    example.printPostOrder();
    example.printPreOrder();
    //cout << example.maxDepth() << endl;
    example.printPaths();
    return 0;
}
