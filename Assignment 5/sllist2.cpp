#include <iostream>
#include "snode.hpp"
#include "sllist.hpp"

using namespace std ;

// Display the content of the list
void SLList::display()
{
    SNode *cur = head ;
    cout<<endl ;
    while(cur!=NULL)
    {
        cout<<cur->data<<"\t";
        cur=cur->next;
    }
    cout<<endl ;
}

// Insert val at the front
void SLList::add(int val)
{
    // create the new node
    SNode *temp=new SNode(val);
    
    // Connect the new node to the list
    temp->next= head; //This makes temp->next point towards the node that was previously the first on the list
    head = temp;     //This makes the pointer of the previously first node on the list point towards the new first node on the list
}

// Insert val at the tail. TBD
void SLList::append(int val)
{
    //Create new node
    if(head==NULL){add(val); return;}
    SNode *temp = new SNode(val);

    //Traverse list until reaching tail
    SNode *cur = head; //Cur will be the pointer of the last node (node->next) after the while loop
    while(cur->next!=NULL){
        cur = cur->next;
    }
    //Temp->next is already NULL per the constructor of the class SNode
    temp->next = NULL;
    //Make the last node point towards temp
    cur->next = temp;
    
    
}

// insert val at position pos. TBD
void SLList::insert(int val, int pos) {
    //Create new node
    SNode *temp = new SNode(val);

    //Traverse list until reaching position pos
    SNode *cur = head; //Cur will be the node->next of the node at position pos at the end of the while loop
    int count = 1;
    while(count < pos && cur!=NULL){
        cur = cur->next;
        ++count;
    }
    if(cur==NULL){cout << "Out of range" << endl; return;};
    //Make temp->next point towards the node at position pos+1
    temp->next = cur->next;
    //Make the node at position pos point towards temp
    cur->next = temp;
}

// Remove the front of the list
int SLList::removeFirst() {
    if(head==NULL) return NOTVALUE ; 
    int data = head->data ;
    SNode* temp = head ;
    head= head->next ;
    delete temp ;
    return data ;
}

// Remove Last element of the list. TBD
int SLList::removeLast() {
    int inf;
    if(head==NULL) return NOTVALUE;
    
    //Traverse the list until last element
    SNode *cur = head; //Cur will be the pointer of the last node (last node->next) after the while loop
    SNode *prev = head;      //Temp will be the second-to-last pointer (it points to the last node)
    while(cur->next!=NULL){
        prev = cur;
        cur = cur->next;
    }
    inf = cur->data; //Retrieve the data from the node
    
    prev->next = NULL; //Make the new last-node pointer (last node->next) equal to NULL
    delete cur;
    return inf ;
}

// Remove the element located at position pos. TBD
int SLList::removePos(int pos) {
    int inf;
    if(head==NULL) return NOTVALUE;
    //Traverse list until reaching position pos
    SNode *cur = head; //Cur will be the node->next of the node at position pos at the end of the while loop
    SNode *prev = head;       //Temp will be the pointer to cur
    int count = 0;
    while(cur!=NULL && count < pos){
        prev = cur;
        cur = cur->next;
        ++count;
    }
    if(cur==NULL) return NOTVALUE; //Check that we are within range
    inf = cur->data;        //Retrieve data from node at position pos
    prev->next = cur->next; //Make prev->next point towards the node at position pos+1
    delete cur;
    return inf;
}

// Remove the node whose data is equal to val. TBD
int SLList::removeData(int val) {
    int inf;
    if(head==NULL) return NOTVALUE;
    SNode *cur = head;
    SNode *prev = head;
    while(cur!=NULL && cur->data!=val){
        prev = cur;
        cur = cur->next;
    }
    if(cur==NULL) return NOTVALUE;
    prev->next = cur->next;
    delete cur;
    return val;
}

// is val in the list. TBD
bool SLList::isIn(int val){
    bool find = false;
    if(head==NULL) return find;
    SNode *cur = head;
    while(cur!=NULL && cur->data!=val){
        cur = cur->next;
    }
    if(cur==NULL) return find;
    find = true;
    return find;
}


