//
//  lparan.cpp
//  ShuntingYard
//
//  Created by Marvin on 4/22/15.
//  Copyright (c) 2015 Marvin. All rights reserved.
//

#include "lparan.h"


lparan::lparan():Token()
{

}
lparan::lparan(char t):Token(LP)
{
    _t=t;
}
int lparan::typeOf()
{
    return LP;
}
char lparan::getChar()
{
    return _t;
}
void lparan::Print()
{
    std::cout<<_t<<" ";
}


