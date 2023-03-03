#ifndef snode_hpp
#define snode_hpp
#include <stdio.h>
#include <ostream>
class SNode
{
    friend class SLList ;
private:
    int data;
    SNode *next;
    
public:
    SNode(int value=0) {
        data= value ;
        next= NULL ;
    }
    // other functions to be added as neededove2
    //funcitons defined by students


    ~SNode(){}
    
    //end of functions defined by student
};
#endif
