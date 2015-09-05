//
//  variable.cpp
//  GraphingCalculator
//
//  Created by Marvin on 4/29/15.
//  Copyright (c) 2015 Marvin. All rights reserved.
//

#include "variable.h"


variable::variable():_t('\0'),Token()
{
    
}
variable::variable(char t):Token(VARIABLE)
{
    _t=t;
}
int variable::typeOf()
{
    return VARIABLE;
}
char variable::getChar()
{
    return _t;
}
void variable::Print()
{
    std::cout<<_t<<" ";
}

