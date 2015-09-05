//
//  mathfunctions.cpp
//  GraphingCalculator
//
//  Created by Marvin on 4/29/15.
//  Copyright (c) 2015 Marvin. All rights reserved.
//

#include "mathfunctions.h"



mathfunctions::mathfunctions():_t(),_ftype(0),Token()
{
    
}
mathfunctions::mathfunctions(std::string t):Token(FUNCTION)
{
    _t=t;
    _ftype=functionType();
}
int mathfunctions::typeOf()
{
    return FUNCTION;
}
int mathfunctions::functionType()
{
        if (_t=="sin")
        {
            _ftype=SIN;
        }
        else if (_t=="cos")
        {
            _ftype=COS;
        }
        else if (_t=="tan")
        {
            _ftype=TAN;
        }
        else if (_t=="cot")
        {
            _ftype=COT;
        }
        else if (_t=="sec")
        {
            _ftype=SEC;
        }
        else if (_t=="csc")
        {
            _ftype=CSC;
        }
        else if (_t=="log")
        {
            _ftype=LOG;
        }
        else if (_t=="ln")
        {
            _ftype=LN;
        }
        else if (_t=="e")
        {
            _ftype=EXP;
        }
        else if (_t=="max")
        {
            _ftype=MAX;
        }else if (_t=="min")
        {
            _ftype=MIN;
        }else if (_t=="n")
        {
            _ftype=NEGATIVE;
        }
        return _ftype;
}
void mathfunctions::Print()
{
    std::cout<<_t<<" ";
}