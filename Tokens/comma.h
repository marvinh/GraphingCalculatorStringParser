//
//  comma.h
//  ShuntingYard
//
//  Created by Marvin on 5/1/15.
//  Copyright (c) 2015 Marvin. All rights reserved.
//

#ifndef __ShuntingYard__comma__
#define __ShuntingYard__comma__

#include <stdio.h>
#include "Token.h"
#include "constants.h"
class comma:public Token
{
public:
    comma();
    comma(char t);
    int typeOf();
    void Print();
private:
    char _t;
};

#endif /* defined(__ShuntingYard__comma__) */
