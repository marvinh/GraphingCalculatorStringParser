//
//  oper.h
//  ShuntingYard
//
//  Created by Marvin on 4/22/15.
//  Copyright (c) 2015 Marvin. All rights reserved.
//

#ifndef __ShuntingYard__oper__
#define __ShuntingYard__oper__

#include <stdio.h>
#include "Token.h"
#include "constants.h"

class oper:public Token
{
public:
    oper();
    
    oper(char t);
    
    //precedence of operator
    int getPrecendence();
    
    int typeOf();
    
    //if right associative return true.
    bool rassociative();
    
    char getChar();
    
    void Print();
private:
    char _t;
};

#endif /* defined(__ShuntingYard__oper__) */
