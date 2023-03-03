//
//  DLCirList.hpp
//  Part 2
//
//  Created by Diego Kleiman on 3/23/18.
//  Copyright © 2018 Diego Kleiman. All rights reserved.
//

#ifndef DLCirList_hpp
#define DLCirList_hpp

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class DLCirList{
private:
    //Class CNode is prvivate because only DLCirList will have access
    //Since the problem involves names of missionaries, the nodes will contain strings
    class CNode{ //Nodes for double-linked circular list
        friend class DLCirList;
    private:
        string S;
        CNode* next;
        CNode* prev;
    public:
        CNode(){next = NULL; prev = NULL; S = "";}
        ~CNode(){}
    };
    //Member variables of DLCirList
    CNode* cursor; //sentinel of list, points at back node
    int num; //number of elements
    
public:
    //Class Iterator is public because member functions will be accessible to users
    class Iterator{ //Iterator for DLCirList
        friend class DLCirList;
    private:
        CNode* v;
        Iterator(CNode* u); //The constructor of the iterator is private because only DLCirList will use this function
    public:
        string& operator*(); //Reference to the element
        bool operator==(const Iterator& p) const; //Compares if two iterators are in the same position
        bool operator!=(const Iterator& p) const; //True if the iterators are at diff positions
        Iterator& operator++(); //Move one position forward
        Iterator& operator--(); //Move one position bacward
    };
    
    //Member functions of DLCirList
    DLCirList();
    DLCirList(DLCirList& list); //Copy constructor
    DLCirList& operator=(const DLCirList& other);
    ~DLCirList();
    int size() const;
    bool empty() const;
    void display();
    Iterator begin(); //const; //sets iterator at beginning position
    Iterator end(); //one place beyod last position
    void insertFront(const string& s);
    void insertBack(const string& s);
    void insert(const Iterator& p, const string& s); //insert after p
    void eraseFront(); //remove first element
    //void eraseBack(); //remove last element
    void erase(Iterator& p, int dir=0); //remove element at p
    string eatMissionary(int N); //Chooses next missionary that will be eaten and returns her name
};
#endif /* DLCirList_hpp */
