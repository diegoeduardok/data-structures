//
//  DLCirList.cpp
//  Part 2
//
//  Created by Diego Kleiman on 3/23/18.
//  Copyright © 2018 Diego Kleiman. All rights reserved.
//

#include "DLCirList.hpp"

DLCirList::Iterator::Iterator(CNode* u){v = u;}

string& DLCirList::Iterator::operator*(){return v->S;}

bool DLCirList::Iterator::operator==(const Iterator& p) const {return v==p.v;}

bool DLCirList::Iterator::operator!=(const Iterator& p) const {return v!=p.v;}

DLCirList::Iterator& DLCirList::Iterator::operator++() {v=v->next; return *this;} //Return *this to make assignments

DLCirList::Iterator& DLCirList::Iterator::operator--() {v=v->prev; return *this;} //Return *this to make assignments

DLCirList::DLCirList(){
    num = 0;
    cursor = NULL;
}

/*DLCirList::DLCirList(DLCirList& list){
    while (!empty()) {eraseFront();} //Empty list
    num = 0; cursor = NULL;
    if (list.cursor==NULL) {return;}
    CNode* temp = list.cursor;
    for (int i = 1; i<=list.num; ++i) {
        insertFront(temp->S); //Adds elements to new list on the front (traversing original backwards)
        temp = temp->prev;
    };
}*/

DLCirList& DLCirList::operator=(const DLCirList& other) {
    while (!empty()) {eraseFront();} //Empty list
    num = 0; cursor = NULL;
    if (other.num == 0) {return (*this);}
    CNode* temp = other.cursor;
    for (int i = 1; i<=other.num; ++i) {
        insertFront(temp->S); //Adds elements to new list on the front (traversing original backwards)
        temp = temp->prev;
    }
    return (*this);
}

DLCirList::~DLCirList(){
    while (!empty()) {eraseFront();}
}

int DLCirList::size()  const {return num;}

bool DLCirList::empty() const {return num == 0;}

void DLCirList::display(){
    CNode* temp = cursor->next;
    for (int i=1; i<=num; ++i) {
        cout << temp->S << ",";
        temp = temp->next;
    }
    cout << endl;
}

DLCirList::Iterator DLCirList::begin(){
    if(empty()){return Iterator(NULL);}//If empty list, returns iterator pointing to NULL
    return Iterator(cursor->next);
}

DLCirList::Iterator DLCirList::end(){
    if(empty()){return Iterator(NULL);}//If empty list, returns iterator pointing to NULL
    return Iterator(cursor);
}

void DLCirList::insertFront(const string& s){insert(begin(), s);}

void DLCirList::insertBack(const string& s){insert(end(), s);}

void DLCirList::insert(const DLCirList::Iterator &p, const string &s){
    if(empty()){
        CNode* n = new CNode;
        cursor = n;
        n->next = n; //n points to itself because it is the only node
        n->prev = n;
        n->S = s;
        ++num;
        return;
    }
    CNode* w = p.v;
    CNode* u = w->prev;
    CNode* n = new CNode; //Node that will be inserted
    n->S = s; //Assign string to new node
    n->next = w; w->prev = n; //n will be inserted before p
    n->prev = u; u->next = n;
    ++num;
}

void DLCirList::eraseFront(){
    Iterator p = begin();
    erase(p);
}

void DLCirList::erase(DLCirList::Iterator &p, int dir){
    if(empty()){return;}
    CNode* e = p.v; //Node that will be removed
    if(dir==0){++p;} else{--p;} //We need to control the direction of the iterator when we are selecting missionaries
    CNode* w = e->next;
    CNode* u = e->prev;
    w->prev = u; u->next = w; //Bridge the gap, leaving e isolated
    //delete e;
    --num;
}

/*string DLCirList::eatMissionary(int N){
    if(num%2 == 0){
        DLCirList tempList(*this);
        Iterator p = tempList.begin();
        while(tempList.num!=1){
            int count = 1;
            while(count <= N){++p;++count;}
            tempList.erase(p); //Eliminate candidates until one person is left
        }
        Iterator q = begin();
        while(q.v->S != p.v->S){++q;}
        erase(q);//Eliminate dinner du jour from original list
        return p.v->S; //Returns the name of the only person still in the list
    }
    else{ //Same thing, but list is traversed in the opposite direction
        DLCirList tempList(*this);
        Iterator p = tempList.begin();
        while(tempList.num!=1){
            int count = 1;
            while(count <= N){--p;++count;}
            tempList.erase(p); //Eliminate candidates until one person is left
        }
        Iterator q = begin();
        while(q.v->S != p.v->S){++q;}
        erase(q);//Eliminate dinner du jour from original list
        return p.v->S; //Returns the name of the only person still in the list
    }
}*/

string DLCirList::eatMissionary(int N){
    if(empty()){return "";}
    DLCirList tempList;
    Iterator p = begin();
    if(num%2 == 0){
        while(num>1){
            for (int i = 1; i <= N; ++i) {cout << p.v->S << ", " << i << endl; ++p;}
            tempList.insertBack(p.v->S);
            erase(p);
        }
        (*this) = tempList;
        return (p.v->S);
    }
    else{
        while(num>1){
            for (int i = 1; i < N; ++i) {++p; cout << p.v->S;}
            tempList.insertBack(p.v->S);
            erase(p, 1);
        }
        (*this) = tempList;
        return (p.v->S);
    }
    
}
