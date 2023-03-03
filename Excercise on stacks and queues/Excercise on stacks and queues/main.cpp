//
//  main.cpp
//  Excercise on stacks and queues
//
//  Created by Diego Kleiman on 3/22/18.
//  Copyright © 2018 Diego Kleiman. All rights reserved.
//

#include <iostream>
#include "Stack.hpp"
#include "Exercise 2.hpp"
#include "Exercise 3.hpp"
#include "Exercise 4.hpp"
#include "DoubleStack.hpp"
#include "ArrayQueue.hpp"
#include "Dequeue.hpp"
#include "Exercise 11.hpp"
using namespace std;


int main() {
    /*Different exercises will be run*/
    int ex=0;
    while (ex < 1 || ex > 14) {
        cout << "Excercise #: ";
        cin >> ex;
        cout << endl;
    }
    if (ex == 1) {
        Stack<int> stack_int(50);
        
        int opt = 0;
        while (opt != 6) {
            cout <<"1. Add item"<<endl<<"2. Delete item"<<endl<<"3. Show size"<<endl<<"4. Find"<<endl<<"5. Display"<<endl<<"6. Exit"<<endl<<"Choose option: ";
            cin >> opt;
            if (opt == 1) {
                cout << "Element: ";
                int elem;
                cin >> elem;
                stack_int.push(elem);
            }
            else if (opt == 2) {
                stack_int.pop();
            }
            else if (opt == 3) {
                cout << stack_int.size() << endl;
            }
            else if (opt == 4) {
                cout << "Element: ";
                int elem;
                cin >> elem;
                int num = stack_int.find(elem);
                if(num>=0){cout << "Element is found at index: "<<num<<endl;}else{cout<<"Not found."<<endl;}
            }
            else if (opt == 5){
                stack_int.display();
            }
        }
        return 0;
    }
    else if (ex == 2){
        cout << "Enter string: ";
        string input;
        cin >> input;
        cout << "Reversed: ";
        ReverseStr(input).display();
        return 0;
    } 
    else if (ex == 3){
        cout << "Enter expression: ";
        string input;
        cin >> input;
        if(CheckParentheses(input)){cout << "Parentheses are balanced."<<endl;}else{cout << "Parentheses are NOT balanced."<<endl;}
        return 0;
    }
    else if (ex == 4){
        cout << "Enter potential palindrome: ";
        string input;
        cin >> input;
        if(CheckPalindrome(input)){cout<<"It's a palindrome."<<endl;}else{cout<<"NOT a palindrome."<<endl;}
        return 0;
    }
    else if (ex == 5){
        DoubleStack DStack(3);
        //DStack.pushBack(2);
        //DStack.pushFront(1);
        //DStack.pushBack(3);
        DStack.display();
        DStack.popBack();
        DStack.display();
        DStack.popFront();
        DStack.display();
        return 0;
    }
    else if (ex == 6){
        ArrayQueue aq(3);
        aq.enqueue(1);
        aq.display(); //1
        aq.enqueue(2);
        aq.display(); //1 2
        aq.enqueue(3);
        aq.display(); //1 2 3
        aq.enqueue(4); //Not included
        aq.display(); //1 2 3
        aq.dequeue();
        aq.display(); //2 3
        aq.dequeue();
        aq.display(); //3
        aq.enqueue(4);
        aq.display(); //3 4
        aq.enqueue(5);
        aq.display(); //3 4 5
        aq.dequeue();
        aq.display(); //4 5
    }
    else if (ex == 7){
        // run ex 7
    }
    else if (ex == 8){
        // run ex 8
    }
    else if (ex == 9){
        Dequeue dq;
        dq.insertFront("hello");
        dq.insertFront("hey there!");
        dq.insertBack("bye!");
        dq.display();
        dq.removeBack();
        dq.display();
        dq.removeFront();
        dq.display();
    }
    else if (ex == 10){
        // run ex 10
    }
    else if (ex == 11){
        Stack<int> myStack;
        myStack.push(4); myStack.push(2); myStack.push(8); myStack.push(2); myStack.push(3);
        myStack.display();
        minToBottom(myStack);
        myStack.display();
    }
    else if (ex == 12){
        // run ex 12
    }
    else if (ex == 13){
        // run ex 13
    }
    else if (ex == 14){
        // run ex 14
    }
}
