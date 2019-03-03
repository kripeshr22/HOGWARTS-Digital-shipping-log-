//
//  Griffin.cpp
//  Project3ben
//
//  Created by Kripesh Ranabhat on 4/25/18.
//  Copyright © 2018 Kripesh Ranabhat. All rights reserved.
//

#include "Griffin.h"

Griffin::Griffin():Standard()
{
    this->id = "o";
}

Griffin::Griffin(string name, string time_stamp, double weight, string id):Standard(name, time_stamp, weight)
{
    this->id=id;
}

string Griffin::get_id()
{
    return this->id;
}

void Griffin::print_info()
{
    Standard::print_info();
    cout << this->id << "Standard-Griffin" << Delivery::get_time_stamp() << endl;
}
