//
//  Token.cpp
//  ShuntingYard
//
//  Created by Marvin on 4/22/15.
//  Copyright (c) 2015 Marvin. All rights reserved.
//

#include "Token.h"


Token::Token():_type(0)
{
    
}
Token::Token(int type):_type(type)
{

}
int Token::typeOf()
{
    return _type;
}
void Token::setType(int type)
{
    _type=type;
}
void Token::Print()
{
    
}
std::ostream& operator<<(std::ostream& outs,Token* & PrintMe)
{

    return outs;
}