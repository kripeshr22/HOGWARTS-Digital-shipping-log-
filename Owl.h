//
//  Owl.hpp
//  Project3ben
//
//  Created by Kripesh Ranabhat on 4/25/18.
//  Copyright © 2018 Kripesh Ranabhat. All rights reserved.
//

#ifndef Owl_h
#define Owl_h

#include "Standard.h"


using namespace std;

class Owl : public Standard
{
    string id;
    
public:
    Owl();
    Owl(string name, string time_stamp, double weight, string id);
    string get_id();
    void print_info();
};

#endif /* Owl_h */
