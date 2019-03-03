//
//  Delivery.hpp
//  Project3ben
//
//  Created by Kripesh Ranabhat on 4/24/18.
//  Copyright © 2018 Kripesh Ranabhat. All rights reserved.
//

#ifndef Delivery_h
#define Delivery_h

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
#include <sstream>

using namespace std;

class Delivery
{
    string sender_name;
    string timestamp;
    
protected:
    Delivery();
    Delivery(string name, string time_stamp);
    
public:
    string get_time_stamp();
    string get_sender_name();
    void set_name(string name);
    virtual void print_info();
    virtual string get_id();
    virtual double get_weight();
    virtual void set_weight(double weight);
};

#endif /* Delivery_h */
