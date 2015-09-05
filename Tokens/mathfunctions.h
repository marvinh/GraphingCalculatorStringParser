//
//  mathfunctions.h
//  GraphingCalculator
//
//  Created by Marvin on 4/29/15.
//  Copyright (c) 2015 Marvin. All rights reserved.
//

#ifndef __GraphingCalculator__mathfunctions__
#define __GraphingCalculator__mathfunctions__

#include <stdio.h>
#include "Token.h"
#include "constants.h"

class mathfunctions:public Token
{
public:
    mathfunctions();
    mathfunctions(std::string t);
    int typeOf();
    int functionType();
    void Print();
private:
    std::string _t;
    int _ftype;
};

#endif /* defined(__GraphingCalculator__mathfunctions__) */
