#include <iostream>

#include "snode.hpp"
#include "sllist.hpp"

using namespace std ;

// a general function to display the list
void Display(SLList lst) {
    
}


//int main(int argc, const char * argv[])
int main()
{
    cout << "Hello, World!\n";
    SLList myl ;
    
    // Test insertion function
    myl.append(25) ;
    myl.display() ;
    myl.add(10) ;
    myl.add(15) ;
    myl.add(20) ;
    myl.display() ;
    myl.append(44) ;
    myl.append(54) ;
    myl.add(06) ;
    myl.display() ;
    myl.insert(12, 0) ;
    myl.display() ;
    myl.insert(200, 1) ;
    myl.display() ;
    myl.insert(300, 10) ;
    myl.display() ;

    // Test Removal functions
    myl.removeLast() ;
    myl.display() ;
    myl.removeFirst() ;
    myl.display() ;
    
    // remove the node containing a specific value
    if(myl.removeData(50)==NOTVALUE) cout<<"value 50 NOT in the list" ;
    else cout<<"50 Removed from the list" ;
    myl.display() ;
  
    // remove the node containing a specific value
    if(myl.removePos(10)==NOTVALUE) cout<<"There no node at pos=10 in the list" ;
    else cout<<"Node at pos=10 REMOVED from the list" ;
    myl.display() ;

    // other functions
    if(myl.isIn(300)) cout<<"We have 300"<<endl ;
    else cout<<"300 in unknmown"<<endl ;

    /*
     Modify the clas list so that you can do the following
     SLList l2(myl) ;
     Display(myl) ;
     Display(l2) ;
     SLList l3 ;
     l3= myl
     Display(l3) ;
     Display(myl) ;
     */
    cout << "\nI am done. Au revoir! \n\n";
    return 0;
}
