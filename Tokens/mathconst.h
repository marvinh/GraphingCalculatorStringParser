//
//  mathconst.h
//  ShuntingYard
//
//  Created by Marvin on 5/1/15.
//  Copyright (c) 2015 Marvin. All rights reserved.
//

#ifndef __ShuntingYard__mathconst__
#define __ShuntingYard__mathconst__

#include <stdio.h>
#include "Token.h"
#include "constants.h"


class mathconst:public Token
{
public:
    mathconst();
    mathconst(std::string t);
    int typeOf();
    int constType();
    void Print();
private:
    std::string _t;
    int _consttype;
};

#endif /* defined(__ShuntingYard__mathconst__) */
