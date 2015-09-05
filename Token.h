//
//  Token.h
//  ShuntingYard
//
//  Created by Marvin on 4/22/15.
//  Copyright (c) 2015 Marvin. All rights reserved.
//

#ifndef __ShuntingYard__Token__
#define __ShuntingYard__Token__

#include <stdio.h>
#include <iostream>
class Token
{
public:
    Token();
    Token(int type);
    //type of token
    //tokens may include subtypes in the respective child
    virtual int typeOf();
    void setType(int type);
    virtual void Print();
private:
    int _type;
};

#endif /* defined(__ShuntingYard__Token__) */
