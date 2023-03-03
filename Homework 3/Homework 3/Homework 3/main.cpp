#include <iostream>
#include <tuple>
#include <string>
#include "BinaryTrees.h"
#include "BinarySearchTrees.h"
#include "OrderedMap.h"
#include "Flight.hpp"

#define PART  3

using namespace std;

int main()
{
#if PART==1
    // LinkedBinaryTree of int type elems
    LinkedBinaryTree<int>  tr ;
    cout<<"Size tr1= "<<tr.getSize()<<endl ;
    tr.addRoot() ;
    tr.expandExternal(tr.root()) ;
    cout<<"Size tr1= "<<tr.getSize()<<endl ;
    
    // LinkedBinaryTree of Entry type elems
    LinkedBinaryTree<Entry<int, string>>  tr2 ;
    cout<<"\nSize tr2= "<<tr2.getSize()<<endl ;
    tr2.addRoot() ;
    tr2.expandExternal(tr2.root()) ;
    cout<<"Size tr2= "<<tr2.getSize()<<endl ;
    
    
#elif PART==2
    // Create a Search tree, fill it, then disply it
    SearchTree<Entry<int,int>> search ;
    cout<<"nSize= "<<search.getSize()<<endl ;

    search.insert(25,125) ;
    search.insert(35,135) ;
    search.insert(55,145) ;
    search.insert(55,155) ;
    cout<<"Size= "<<search.getSize()<<endl ;
    
    SearchTree<Entry<int,int>>::Iterator iter=search.begin() ;
    while( !(iter == search.end())) {
        cout<<(*iter).key()<<", "<<(*iter).value()<<endl ;
        ++iter;
    }

#elif PART==3
    // Create an OrderedMap, fill it, then disply it
    OrderedMap<int, int> oMap ;
    cout<<"nSize= "<<oMap.getSize()<<endl ;
    oMap.put(25,125) ;
    oMap.put(35,135) ;
    oMap.put(55,145) ;
    oMap.put(55,155) ;
    cout<<"nSize= "<<oMap.getSize()<<endl ;
    SearchTree<Entry<int,int>>::Iterator iter=oMap.begin() ;
    while( !(iter == oMap.end())) {
        cout<<(*iter).key()<<", "<<(*iter).value()<<endl ;
        ++iter;
    }
    
    // Testing functions defined by student
    SearchTree<Entry<int,int>>::Iterator iter2 = oMap.firstEntry();
    cout<<(*iter2).key()<<", "<<(*iter2).value()<<endl ;
    SearchTree<Entry<int,int>>::Iterator iter3 = oMap.lastEntry();
    cout<<(*iter3).key()<<", "<<(*iter3).value()<<endl ;
    SearchTree<Entry<int,int>>::Iterator iter4 = oMap.ceilingEntry(35);
    cout<<(*iter4).key()<<", "<<(*iter4).value()<<endl ;
    SearchTree<Entry<int,int>>::Iterator iter5 = oMap.floorEntry(35);
    cout<<(*iter5).key()<<", "<<(*iter5).value()<<endl ;
    SearchTree<Entry<int,int>>::Iterator iter6 = oMap.lowerEntry(35);
    cout<<(*iter6).key()<<", "<<(*iter6).value()<<endl ;
    SearchTree<Entry<int,int>>::Iterator iter7 = oMap.higherEntry(35);
    cout<<(*iter7).key()<<", "<<(*iter7).value()<<endl ;

    // Testing OrderedMap using Flight Databases (flightDB)
    typedef tuple<string, string, string, string> flight;
    typedef tuple<string, string, string, string, int> flightDetails;
    OrderedMap<flight, flightDetails> flightDB;
    
    flight f1(make_tuple("ORD", "PDV", "05May", "09:53"));
    flight f2(make_tuple("ORD", "PDV", "05May", "13:29"));
    flight f3(make_tuple("ORD", "PDV", "05May", "17:39"));
    flight f4(make_tuple("ORD", "PDV", "05May", "19:50"));
    
    flightDetails d1(make_tuple("AA1840","F5","Y15","02:05",251));
    flightDetails d2(make_tuple("AA600","F2","Y0","02:16",713));
    flightDetails d3(make_tuple("AA416","F3","Y9","02:09",365));
    flightDetails d4(make_tuple("AA1828","F9","Y25","02:13",186));
    
    flightDB.put(f1, d1); flightDB.put(f2, d2); flightDB.put(f3, d3); flightDB.put(f4, d4);
    
    //Now that we have a database, we can test the functions (only ceilingEntry is shown here)
    
    flight inputKey(make_tuple("ORD", "PDV", "05May", "10:00")); //User wants flight departing at or after 10:00
    
    SearchTree<Entry<flight,flightDetails>>::Iterator iterFlight = flightDB.ceilingEntry(inputKey); //Gets next flight
    displayFlight((*iterFlight).key()); //Prints next flight (departing at 13:29)
    displayFlightDetails((*iterFlight).value()); //Prints details of flight
    
    
#endif
    return 0;
}


