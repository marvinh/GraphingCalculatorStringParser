//
//  mathconst.cpp
//  ShuntingYard
//
//  Created by Marvin on 5/1/15.
//  Copyright (c) 2015 Marvin. All rights reserved.
//

#include "mathconst.h"

mathconst::mathconst():_t(),_consttype(-1),Token()
{
    
}
mathconst::mathconst(std::string t):Token(CONSTANT)
{
    _t=t;
    _consttype=-1;
}
int mathconst::typeOf()
{
    return CONSTANT;
}
int mathconst::constType()
{
    if(_t=="pi")
    {
        _consttype=PI;
    }

    return _consttype;
}
void mathconst::Print()
{
    std::cout<<_t<<" ";
}