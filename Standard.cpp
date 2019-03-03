//
//  Standard.cpp
//  Project3ben
//
//  Created by Kripesh Ranabhat on 4/25/18.
//  Copyright © 2018 Kripesh Ranabhat. All rights reserved.
//

#include "Standard.h"

Standard::Standard()
{
    
}

Standard::Standard(string name, string time_stamp, double weight):Delivery(name, time_stamp)
{
    this->weight = weight;
}

double Standard::get_weight()
{
    Delivery::get_weight();
    return this->weight;
}

void Standard::set_weight(double weight)
{
    
}

void Standard::print_info()
{
    Delivery::print_info();
}

string Standard::get_id()
{
    Delivery::get_id();
    return " ";
}
