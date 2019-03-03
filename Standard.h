//
//  Standard.hpp
//  Project3ben
//
//  Created by Kripesh Ranabhat on 4/25/18.
//  Copyright © 2018 Kripesh Ranabhat. All rights reserved.
//

#ifndef Standard_h
#define Standard_h

#include "Delivery.h"


using namespace std;

class Standard : public Delivery
{
    double weight;
    
protected:
    Standard();
    Standard(string name, string time_stamp, double weight);
    
public:
    double get_weight();
    void set_weight(double weight);
    void print_info();
    virtual string get_id();
};


#endif /* Standard_h */
