//
//  Griffin.hpp
//  Project3ben
//
//  Created by Kripesh Ranabhat on 4/25/18.
//  Copyright © 2018 Kripesh Ranabhat. All rights reserved.
//

#ifndef Griffin_h
#define Griffin_h

#include "Standard.h"



class Griffin : public Standard
{
    string id;
    
public:
    Griffin();
    Griffin(string name, string time_stamp, double weight, string id);
    string get_id();
    void print_info();
};
#endif /* Griffin_h */
