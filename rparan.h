//
//  rparan.h
//  ShuntingYard
//
//  Created by Marvin on 4/22/15.
//  Copyright (c) 2015 Marvin. All rights reserved.
//

#ifndef __ShuntingYard__rparan__
#define __ShuntingYard__rparan__

#include <stdio.h>
#include "Token.h"
#include "constants.h"
class rparan:public Token
{
public:
    rparan();
    rparan(char t);
    int typeOf();
    char getChar();
    void Print();
private:
    char _t;
};

#endif /* defined(__ShuntingYard__rparan__) */
