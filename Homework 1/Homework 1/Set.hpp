//
//  Set.hpp
//  Homework 1
//
//  Created by Diego Kleiman on 3/1/18.
//  Copyright © 2018 Diego Kleiman. All rights reserved.
//

#ifndef Set_hpp
#define Set_hpp
#include <stdio.h>

class Set{
private:
    int MaxCard; //Maximal cardinality of the set
    int Card; //Effective number of elements in the set
    int* Elems = {}; //Array contining elements of the set
public:
    Set(){MaxCard = 0; Card = -1;} //Default constructor
    Set(int maxcard); //Constructor with max capacity maxcard
    Set(const Set& s); //Copy constructor
    void AddElem(int e); //Add element (adds at the back)
    int RmvElem(int pos); //Removes element at the front and shifts others
    bool Member(int e); //Checks if e is in the set
    void Copy(const Set& s); //Copies a set into another set (i.e. assignment operator)
    bool Equal(const Set& s); //Checks if two sets are the same
    void Intersect(const Set& s, Set& inters); //Computes the intersection of a set
    void Union(const Set& s, Set& uni); //Computes the union of a set
    void Print(); //Displays set
    Set operator=(const Set& s); //Assignment operator
    bool operator&(int e); //Checks if e is member of the set
    bool operator==(const Set& other); //Verifies equality of the sets
    bool operator!=(const Set& other); //Verifies inequality of the sets
    Set operator*(const Set& other); //Computes intersection of the sets
    Set operator+(const Set& other); //Computes union of the sets
    Set operator-(const Set& other); //Computes difference of the sets
    bool operator<=(Set& other); //Verifies inclusion of one set in another
    void operator<<(Set other); //Displays set
    void operator>>(Set other); //Input content of the set
    ~Set(){delete[] Elems; Elems=NULL;} //Destructor
    
    //Extra functions
    int getCard(){return Card;}
    int getMaxCard(){return MaxCard;}
    void Difference(const Set& s, Set& diff); //Computes symmetric difference of two sets
};


#endif /* Set_hpp */
