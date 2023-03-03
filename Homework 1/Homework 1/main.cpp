//
//  main.cpp
//  Homework 1
//
//  Created by Diego Kleiman on 3/1/18.
//  Copyright © 2018 Diego Kleiman. All rights reserved.
//

#include <iostream>
#include "Set.hpp"
using namespace std;

int main() {
    //Test constructors. Cardinality is initialized at -1 and Max Cardinality is 0 unless specified by the user.
    
    cout << "Test constructors" << endl;
    cout << "Default constructor:" << endl;;
    Set placeholder;
    cout << "Cardinality: " << placeholder.getCard() <<", Max Cardinality: "<< placeholder.getMaxCard() << endl;
    //Cardinality: -1, Max Cardinality: 0
    cout << "Constructor with MaxCard = 4:" << endl;
    Set example(4);
    cout << "Cardinality: " << example.getCard() <<", Max Cardinality: "<< example.getMaxCard() << endl;
    //Cardinality: -1, Max Cardinality: 3 - Note: MaxCard is always 1 less than the number entered to be consistent with the size of the set
    
    //Test AddElem by filling up example, also test Print and << (same functionality)
    
    cout<<"\n\nTest AddElem" << endl;
    example.Print(); //Since it's empty it will print ∅ (empty set symbol)
    example.AddElem(1);
    example.Print(); //Prints {1}
    example.AddElem(0); //Elements are placed in incresing order
    example.Print(); //Prints {0, 1}
    example.AddElem(2);
    example.AddElem(3);
    example<<placeholder; //Prints {0, 1, 2, 3}
    example.AddElem(4); //There is not enough space, so it prints "No more space" and 4 is not added
    example<<placeholder; //Prints {0, 1, 2, 3} again
    
    //Test RmvElem by emptying example
    cout << "\n\nTest RmvElem" << endl;
    example.Print();
    cout << example.RmvElem(10) << endl; //Out of range, returns NOTVALUE and leaves set unchanged
    example.Print();
    cout << example.RmvElem(1) << endl; //Removes 1
    example.Print();
    cout << example.RmvElem(0) << endl; //Removes 0
    example.Print();
    cout << example.RmvElem(1) << endl; //Removes 3
    example.Print();
    cout << example.RmvElem(0) << endl; //Removes 2
    example.Print();
    cout << example.RmvElem(3) << endl; //Cannot remove elements from empty set, returns NOTVALUE
    example.Print();
    
    //Test Copy (functions like assignemnt operator), and equality operators Equality, ==, !=
    cout<< "\n\nTest Copy, =, and copy constructor. Also test Equal, ==, and !=" << endl;
    example.AddElem(0);example.AddElem(1);example.AddElem(2);example.AddElem(3); //Fill up example again
    Set copy_example;
    copy_example.Copy(example);
    copy_example.Print(); //Prints {0, 1, 2, 3}
    Set copy_example2(example);
    copy_example2.Print();
    Set copy_example3;
    copy_example3 = example;
    copy_example3.Print();
    if(copy_example==example){cout<<"Copy and == work!"<<endl;}
    if(copy_example2.Equal(example)){cout<<"Copy constructor and Equal work!"<<endl;}
    if(copy_example3!=example){cout<<"Error"<<endl;}else{cout<<"Assignment operator and != work!"<<endl;}
    
    //Test Member and & (same functionality)
    cout<< "\n\nTest Member and &" << endl;
    example.Print();
    if(example.Member(2)){cout<<"2 is in example"<<endl;}else{cout<<"2 is not in example"<<endl;}
    if(example.Member(5)){cout<<"5 is in example"<<endl;}else{cout<<"5 is not in example"<<endl;}
    if(example&0){cout<<"0 is in example"<<endl;}else{cout<<"0 is not in example"<<endl;}
    if(example&-5){cout<<"-5 is in example"<<endl;}else{cout<<"-5 is not in example"<<endl;}
    
    
    //Test Intersect and * (same functionality)
    cout << "\n\nTest Intersect and *"<<endl;
    Set example2(3); example2.AddElem(0);example2.AddElem(-8);example2.AddElem(3);
    cout << "Set 1: ";
    example.Print();
    cout << "Set 2: ";
    example2.Print();
    cout << "Intersection: ";
    Set intersection;
    example.Intersect(example2, intersection);
    intersection.Print();
    cout <<"Intersection once more: ";
    Set intersection2 = example*example2;
    intersection2.Print();
    
    //Test Union and + (same functionality)
    cout << "\n\nTest Union and +"<<endl;
    cout << "Set 1: ";
    example.Print();
    cout << "Set 2: ";
    example2.Print();
    cout << "Union: ";
    Set Union;
    example.Union(example2, Union);
    Union.Print();
    cout <<"Union once more: ";
    Set Union2 = example+example2;
    Union2.Print();
    
    //Test Difference and - (symmetric difference of sets)
    cout << "\n\nTest Difference and -"<<endl;
    cout << "Set 1: ";
    example.Print();
    cout << "Set 2: ";
    example2.Print();
    cout << "Symmetric difference: ";
    Set difference;
    example.Difference(example2, difference);
    difference.Print();
    cout <<"Symmetric difference once more: ";
    Set difference2 = example-example2;
    difference2.Print();
    
    //Test <= (check if it is subset)
    cout << "\n\nTest <="<<endl;
    Set subset(2); subset.AddElem(0); subset.AddElem(1);
    cout << "Subset: ";
    subset.Print();
    cout << "Superset: ";
    example.Print();
    if(subset<=example){cout << "<= works!"<<endl;}
    cout << "Not subset: ";
    example2.Print();
    if(example2<=example){cout<< "Example 2 is subset of example (error)."<<endl;}else{cout<<"<= works again!"<<endl;}
    
    //Test >> (manual input)
    cout << "\n\nTest >>"<<endl;
    Set example3;
    example3>>placeholder; //Fill up as wanted. MaxCard MUST BE GREATER THAN 0!
    example3.Print(); //Prints result
    
    return 0;
}
