//
//  Flight.hpp
//  Homework 3
//
//  Created by Diego Kleiman on 5/6/18.
//  Copyright © 2018 Diego Kleiman. All rights reserved.
//

#ifndef Flight_hpp
#define Flight_hpp

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

//Display functions for tuples
typedef tuple<string, string, string, string> flight;
typedef tuple<string, string, string, string, int> flightDetails;
void displayFlight(const flight& f){
    cout<<"("<<get<0>(f)<<", "<<get<1>(f)<<", "<<get<2>(f)<<", "<<get<3>(f)<<")"<<endl;
}
void displayFlightDetails(const flightDetails& f){
    cout<<"("<<get<0>(f)<<", "<<get<1>(f)<<", "<<get<2>(f)<<", "<<get<3>(f)<<", "<<get<4>(f)<<")"<<endl;
}
#endif /* Flight_hpp */
