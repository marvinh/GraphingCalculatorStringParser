//
//  num.h
//  ShuntingYard
//
//  Created by Marvin on 4/22/15.
//  Copyright (c) 2015 Marvin. All rights reserved.
//

#ifndef __ShuntingYard__num__
#define __ShuntingYard__num__

#include <stdio.h>
#include "Token.h"
#include "constants.h"
class num:public Token
{
public:
    num();
    num(double d);
    int typeOf();
    double getNum();
    void Print();
private:
    double _d;
};

#endif /* defined(__ShuntingYard__num__) */
