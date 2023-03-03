#ifndef sllist_hpp
#define sllist_hpp

#include <iostream>
#include "snode.hpp"
const int NOTVALUE= 9999 ;

class SLList
{
private:
    SNode *head;
    
public:
    SLList() {
        head=NULL;
    }
    
    // List destructor TBD
    ~SLList() {
        
    }
    
    // Dispalay the content of the list
    void display() ;
    
    // Insertion in the list. Return the inserted data
    void add(int val) ;              // insert val at the front
    void append(int val) ;           // insert val at the tail
    void insert(int val, int pos) ;  // insert val at position pos
    
    // Removing from the list. Retun the removed data or 9999 if no data
    int removeFirst() ;
    int removeLast() ;
    int removePos(int pos) ;
    int removeData(int val) ;
    
    // other functions
    bool isEmpty() {
        return (head==NULL) ;
    }
    bool isIn(int val) ; // is val in the list
};

#endif
