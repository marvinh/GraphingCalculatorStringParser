//
//  quickTokenize.cpp
//  ShuntingYard
//
//  Created by Marvin on 4/24/15.
//  Copyright (c) 2015 Marvin. All rights reserved.
//

#include "quickTokenize.h"


QuickTokenize::QuickTokenize()
{
    _type=-1;
    _pos=0;
    numbers="0123456789.";
    operators="*^+-/";
    left="(";
    right=")";
    alpha="abcdefghijklmnopqrstuvwxyz";
    space=" ";
    comma=",";
}
QuickTokenize::QuickTokenize(string s)
{
    _type=-1;
    _s=s;
    _pos=0;
    _d=0.0;
    
    numbers="0123456789.";
    operators="*^+-/";
    left="(";
    right=")";
    alpha="abcdefghijklmnopqrstuvwxyz";
    space=" ";
    comma=",";
    
}
void QuickTokenize::d_conversion(string s)
{
    _d=stod(s);
}
double QuickTokenize::getConversion()
{
    return _d;
}
int QuickTokenize::stringCompare(std::string compare)
{
    if(compare=="x")
    {
        _type=VARIABLE;
        return _type;
    }
    else if(compare=="sin"||compare=="cos"||compare=="tan"
            ||compare=="cot"||compare=="sec"||compare=="csc"
            ||compare=="log"||compare=="ln"||compare=="e"
            ||compare=="max"||compare=="min"||compare=="n")
    {
        _type=FUNCTION;
    }
    else if (compare=="pi")
    {
        _type=CONSTANT;
    }
    else
    {
        _type=-1;
    }
    return _type;
}
int QuickTokenize::ofType()
{
    return _type;
}
string QuickTokenize::nextToken()
{
    int type=sType();
    string s;
    if(type==NUM)
    {
        int j=_s.find_first_not_of(numbers,_pos);
        s.assign(_s,_pos,(j-_pos));
        d_conversion(s);
        _pos=_pos+(j-_pos);
    }
    else if (type==OP)
    {
        s.assign(_s,_pos,1);
        _pos=_pos+1;
    }
    else if (type==LP)
    {
        s.assign("(");
        _pos=_pos+1;
    }
    else if (type==RP)
    {
        s.assign(")");
        _pos=_pos+1;
    }
    else if (type==SPACE)
    {
        s.assign(" ");
        _pos=_pos+1;
    }
    else if(type==ALPHA)
    {
        int j=_s.find_first_not_of(alpha,_pos);
        s.assign(_s,_pos,(j-_pos));
        _type=stringCompare(s);
        _pos=_pos+(j-_pos);
    }
    else if (type==COMMA)
    {
        s.assign(",");
        _pos=_pos+1;
    }
    else
    {
        _pos+=1;
    }
    
    return s;
}
bool QuickTokenize::empty()
{
    if (_pos>=_s.length()) {
        return true;
    }else{
        return false;
    }
}
int QuickTokenize::sType()
{
    int a=numbers.find(_s[_pos]);
    int b=operators.find(_s[_pos]);
    int c=left.find(_s[_pos]);
    int d=right.find(_s[_pos]);
    int e=space.find(_s[_pos]);
    int f=alpha.find(_s[_pos]);
    int g=comma.find(_s[_pos]);
    if(a!=-1)
    {
        _type=NUM;
    }
    else if(b!=-1)
    {
        _type=OP;
    }
    else if(c!=-1)
    {
        _type=LP;
    }
    else if(d!=-1)
    {
        _type=RP;
    }
    else if (e!=-1)
    {
        _type=SPACE;
    }
    else if(f!=-1)
    {
        _type=ALPHA;
    }
    else if (g!=-1)
    {
        _type=COMMA;
    }
    else
    {
        _type=-1;
    }
    return _type;
}
