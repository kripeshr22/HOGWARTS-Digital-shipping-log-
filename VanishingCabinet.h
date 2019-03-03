//
//  VanishingCabinet.hpp
//  Project3ben
//
//  Created by Kripesh Ranabhat on 4/25/18.
//  Copyright © 2018 Kripesh Ranabhat. All rights reserved.
//

#ifndef VanishingCabinet_h
#define VanishingCabinet_h

#include "Delivery.h"


using namespace std;

class VanishingCabinet : public Delivery
{
    double weight;
    string id;
    
public:
    VanishingCabinet();
    VanishingCabinet(string name, string time_stamp, double weight, string id);
    double get_weight();
    void set_weight(double weight);
    string get_id();
    void print_info();
};
#endif /* VanishingCabinet_h */
