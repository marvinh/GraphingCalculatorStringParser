//
//  oper.cpp
//  ShuntingYard
//
//  Created by Marvin on 4/22/15.
//  Copyright (c) 2015 Marvin. All rights reserved.
//

#include "oper.h"


oper::oper():Token()
{
    
}
oper::oper(char t):Token(OP)
{
    _t=t;
}
int oper::typeOf()
{
    return OP;
}
char oper::getChar()
{
    return _t;
}
bool oper::rassociative()
{
    if(getPrecendence()==3)
    {
        return true;
    }else{
        return false;
    }
}
int oper::getPrecendence()
{
    switch (_t) {
        case '+':
        case '-':
            return 1;
            break;
        case '*':
        case '/':
            return 2;
            break;
        case '^':
            return 3;
            break;
    }
    return 4;
}
void oper::Print()
{
    std::cout<<_t<<" ";
}


