//
//  VanishingCabinet.cpp
//  Project3ben
//
//  Created by Kripesh Ranabhat on 4/25/18.
//  Copyright © 2018 Kripesh Ranabhat. All rights reserved.
//

#include "VanishingCabinet.h"

VanishingCabinet::VanishingCabinet():Delivery()
{
    this->id = "-";
}

VanishingCabinet::VanishingCabinet(string name, string time_stamp, double weight, string id):Delivery(name, time_stamp)
{
    this->weight = weight;
    this->id = id;
}

string VanishingCabinet::get_id()
{
    return this->id;
}

double VanishingCabinet::get_weight()
{
    Delivery::get_weight();
    return this->weight;
}

void VanishingCabinet::set_weight(double weight)
{
    
}

void VanishingCabinet::print_info()
{
    Delivery::print_info();
    cout << this->id << "Vanishing Cabinet" << Delivery::get_time_stamp() << endl;
}
