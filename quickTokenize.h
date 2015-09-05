//
//  quickTokenize.h
//  ShuntingYard
//
//  Created by Marvin on 4/24/15.
//  Copyright (c) 2015 Marvin. All rights reserved.
//

#ifndef __ShuntingYard__quickTokenize__
#define __ShuntingYard__quickTokenize__

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include "constants.h"
using namespace std;
class QuickTokenize
{
public:
    QuickTokenize();
    
    QuickTokenize(string s);
    
    string nextToken();
    
    //convert if type is number
    void d_conversion(string s);
    
    //get number
    double getConversion();
    
    //determining which types an alpha string would be in
    int stringCompare(std::string compare);
    
    //get all types
    int ofType();
    
    //used to differentiate first 4 character sets from alphabetical set.
    int sType();
    
    //if end of string is reached its empty
    bool empty();
    
private:
    string _s;
    double _d;
    int _type;
    int _pos;
    string numbers;
    string right;
    string left;
    string operators;
    string alpha;
    string space;
    string comma;
};


#endif /* defined(__ShuntingYard__quickTokenize__) */
