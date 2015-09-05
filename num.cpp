//
//  num.cpp
//  ShuntingYard
//
//  Created by Marvin on 4/22/15.
//  Copyright (c) 2015 Marvin. All rights reserved.
//

#include "num.h"



num::num():Token()
{
    
}
num::num(double d):Token(NUM)
{
    _d=d;
}
int num::typeOf()
{
    return NUM;
}
double num::getNum()
{
    return _d;
}
void num::Print()
{
    std::cout<<_d<<" ";
}


