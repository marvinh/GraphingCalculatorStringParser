//
//  comma.cpp
//  ShuntingYard
//
//  Created by Marvin on 5/1/15.
//  Copyright (c) 2015 Marvin. All rights reserved.
//

#include "comma.h"


comma::comma():Token()
{
    
}
comma::comma(char t):Token(COMMA)
{
    _t=t;
}
int comma::typeOf()
{
    return COMMA;
}
void comma::Print()
{
    std::cout<<_t<<" ";
}


