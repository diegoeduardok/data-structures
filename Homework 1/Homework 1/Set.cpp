//
//  Set.cpp
//  Homework 1
//
//  Created by Diego Kleiman on 3/1/18.
//  Copyright © 2018 Diego Kleiman. All rights reserved.
//

#include "Set.hpp"
#include <iostream>
#include <vector>

using namespace std;
const int NOTVALUE = 99999;

Set::Set(int maxcard){
    MaxCard = maxcard-1;
    Card = -1;
    Elems = new int[MaxCard]; //Allocate space for elements of the set
}
Set::Set(const Set& s){
    (*this).Copy(s); 
}
void Set::AddElem(int e){
    if (Card==MaxCard) {cout <<"No more space"<<endl;return;}//Check if there is space
    if (Card==-1) {Elems[0]=e;++Card;return;}//First element
    for (int i=0; i<=Card; ++i) {
        if (Elems[i]==e){return;}//If element is present already, does not change anything
        if (Elems[i]>e) {//Add elements in increasing order
            for (int j=Card; j>=i; --j) {
                Elems[j+1] = Elems[j];}//Shift one position to free pointer at position i
            Elems[i] = e;
            ++Card;
            return;
        }
    }
    if(e>Elems[Card]){Elems[Card+1]=e;++Card;} //Add as last element if it is greater than the rest
}
int Set::RmvElem(int pos){
    if(Card==-1){return NOTVALUE;} //Empty set, no element to remove
    if(pos>Card){return NOTVALUE;} //No element at position pos
    int removed  = Elems[pos];
    for (int i=pos; i<=Card; ++i) {Elems[i] = Elems[i+1];} //Shift elements
    --Card;
    return removed; //Returns removed element
}
bool Set::Member(int e){
    if (Card==-1) {return false;}
    for (int i=0; i<=Card; ++i) {
        if (Elems[i]==e) {return true;}
    }
    return false;
}
void Set::Copy(const Set& s){
    MaxCard = s.MaxCard;
    Card = s.Card;
    Elems = new int[MaxCard];
    if(s.Card>-1){
        for (int i=0; i<=Card; ++i) {Elems[i] = s.Elems[i];}
    }
}
bool Set::Equal(const Set& s){
    if(Card!=s.Card){return false;}//First check cardinality is the same
    if(Card==-1){return true;}//The two sets are empty (hence they are equal)
    for (int i=0; i<=Card; ++i) {
        if(Elems[i]!=s.Elems[i]){return false;}//Check all elements are the same if the sets are non-empty
    }
    return true;
}
void Set::Intersect(const Set& s, Set& inters){
    if(Card==-1|s.Card==-1){return;} //Inters is empty if one or both the sets are empty
    int count = 1;
    for (int i=0; i<=Card; ++i) {
        for (int j=0; j<=s.Card; ++j) {
            if(Elems[i]==s.Elems[j]){++count;} //Determine size of intersection
        }
    }
    Set intersection(count); //Instantiate intersection with the right size
    for (int i=0; i<=Card; ++i) {
        for (int j=0; j<=s.Card; ++j) {
            if(Elems[i]==s.Elems[j]){intersection.AddElem(Elems[i]);} //Add common elements
        }
    }
    inters.Copy(intersection);
}
void Set::Union(const Set& s, Set& uni){
    if (Card==-1 && s.Card==-1) {return;} //Union is empty if both sets are empty
    else if (Card==-1){uni.Copy(s);return;} //If set 1 is empty, union is set 2
    else if(s.Card==-1){uni.Copy(*this);return;}//If set 2 is empty, union is set 1
    //If both sets non-empty...
    Set SUnion(Card + s.Card + 1); //Max cardinality is the sum of the two sets' cardinalities (+1 because Card starts at -1)
    int i = 0;
    while(i<=Card) {SUnion.AddElem(Elems[i]);++i;} //Adds elements from one set
    i = 0;
    while(i<=s.Card) {SUnion.AddElem(s.Elems[i]);++i;} //Adds elements from the other set
    uni.Copy(SUnion);
}
void Set::Print(){
    if (Card==-1) {cout << "∅" << endl; return;}//Prints empty set if no elements exist
    cout<<"{";
    for (int i=0; i<Card; ++i) {
        cout << Elems[i] <<", ";
    }
    cout << Elems[Card] << "}" << endl;
}
Set Set::operator=(const Set& s){
    (*this).Copy(s);
    return *this;
}
bool Set::operator&(int e){
    if (Card==-1) {return false;}
    for (int i=0; i<=Card; ++i) {
        if (Elems[i]==e) {return true;}
    }
    return false;
}
bool Set::operator==(const Set& other){
    if(Card!=other.Card){return false;}//First check cardinality is the same
    if(Card==-1){return true;}//The two sets are empty (hence they are equal)
    for (int i=0; i<=Card; ++i) {
        if(Elems[i]!=other.Elems[i]){return false;}//Check all elements are the same if the sets are non-empty
    }
    return true;
}
bool Set::operator!=(const Set &other){
    if(*this==other){return false;} else{return true;}
}
Set Set::operator*(const Set& other){
    Set intersection;
    (*this).Intersect(other, intersection);
    return intersection;
}
Set Set::operator+(const Set& other){
    Set sum;
    (*this).Union(other, sum);
    return sum;
}
Set Set::operator-(const Set& other){
    Set diff;
    (*this).Difference(other, diff);
    return diff;
}
bool Set::operator<=(Set& other){
    if (Card==-1) {return true;} //The empty set is included in any other set
    if (other.Card==-1) {return false;} //The empty set only contains itself
    for (int i=0; i<=Card; ++i) {
        if(other.Member(Elems[i])){}else{return false;}
    }
    return true;
}
void Set::operator<<(Set other){
    (*this).Print();
}
void Set::operator>>(Set other){
    int maxcard = 0;
    while(maxcard<=0){
        cout << "Specify maximum cardinality (MUST BE GREATER THAT 0): ";
        cin >> maxcard;
    }
    Set input(maxcard);
    cout << endl << "Enter elements: " << endl;
    int num;
    for (int i = 0; i<maxcard; ++i) {
        cin >> num;
        input.AddElem(num);
    }
    (*this).Copy(input);
}

//Extra functions
void Set::Difference(const Set &s, Set &diff){
    if (Card==-1 && s.Card==-1) {return;} //Diff is empty if both sets are empty
    else if (Card==-1){diff.Copy(s);return;} //If set 1 is empty, diff is set 2
    else if(s.Card==-1){diff.Copy(*this);return;}//If set 2 is empty, diff is set 1
    //If both sets non-empty...
    Set difference(Card + s.Card + 1); //Instantiate difference with the max possible size
    bool add = true; //Will decide if element is unshared (i.e. will be added to difference)
    for (int i=0; i<=Card; ++i) {
        add = true;
        for (int j=0; j<=s.Card; ++j) {
            if(Elems[i]==s.Elems[j]){add = false;} //Determine unshared elements
        }
        if(add){difference.AddElem(Elems[i]);} //Add elements found in set 1 but not in set 2
    }
    for (int i=0; i<=s.Card; ++i) {
        add = true;
        for (int j=0; j<=Card; ++j) {
            if(s.Elems[i]==Elems[j]){add = false;} //Determine unshared elements
        }
        if(add){difference.AddElem(s.Elems[i]);} //Add elements found in set 2 but not in set 1
    }
    diff.Copy(difference);
    
}
