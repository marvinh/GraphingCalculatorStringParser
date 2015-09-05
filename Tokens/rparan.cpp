//
//  rparan.cpp
//  ShuntingYard
//
//  Created by Marvin on 4/22/15.
//  Copyright (c) 2015 Marvin. All rights reserved.
//

#include "rparan.h"


rparan::rparan():Token()
{
    
}
rparan::rparan(char t):Token(RP)
{
    _t=t;
}
int rparan::typeOf()
{
    return RP;
}
char rparan::getChar()
{
    return _t;
}
void rparan::Print()
{
    std::cout<<_t<<" ";
}



