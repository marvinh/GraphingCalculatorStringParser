//
//  lparan.h
//  ShuntingYard
//
//  Created by Marvin on 4/22/15.
//  Copyright (c) 2015 Marvin. All rights reserved.
//

#ifndef __ShuntingYard__lparan__
#define __ShuntingYard__lparan__

#include <stdio.h>
#include "Token.h"
#include "constants.h"
class lparan:public Token
{
public:
    lparan();
    lparan(char t);
    int typeOf();
    char getChar();
    void Print();
private:
    char _t;
};


#endif /* defined(__ShuntingYard__lparan__) */
