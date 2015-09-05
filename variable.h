//
//  variable.h
//  GraphingCalculator
//
//  Created by Marvin on 4/29/15.
//  Copyright (c) 2015 Marvin. All rights reserved.
//

#ifndef __GraphingCalculator__variable__
#define __GraphingCalculator__variable__

#include <stdio.h>
#include "Token.h"
#include "constants.h"
class variable:public Token
{
public:
    variable();
    variable(char t);
    char getChar();
    
    int typeOf();
    void Print();
private:
    char _t;
};

#endif /* defined(__GraphingCalculator__variable__) */
