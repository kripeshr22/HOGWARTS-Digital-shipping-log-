//
//  Delivery.cpp
//  Project3ben
//
//  Created by Kripesh Ranabhat on 4/24/18.
//  Copyright © 2018 Kripesh Ranabhat. All rights reserved.
//

#include "Delivery.h"

Delivery::Delivery()
{
    
}

Delivery::Delivery(string name, string time_stamp)
{
    this->sender_name = name;
    this->timestamp = time_stamp;
}

string Delivery::get_time_stamp()
{
    return this->timestamp;
}

string Delivery::get_sender_name()
{
    return this->sender_name;
}

void Delivery::set_name(string name)
{
    this->sender_name = name;
}

void Delivery::print_info()
{
    cout << this->sender_name << " ";
}

string Delivery::get_id()
{
    return " ";
}

double Delivery::get_weight()
{
    return 1.1;
}

void Delivery::set_weight(double weight)
{
    
}
