//
//  Cartesian.cpp
//  GraphingCalculator
//
//  Created by Marvin on 4/28/15.
//  Copyright (c) 2015 Marvin. All rights reserved.
//

#include "Cartesian.h"

Cartesian::Cartesian():_x(0),_y(0)
{
    
}
Cartesian::Cartesian(double x,double y):_x(x),_y(y)
{
    
}
void Cartesian::SetX(double x)
{
    _x=x;
}
void Cartesian::SetY(double y)
{
    _y=y;
}
void Cartesian::SetXY(double x, double y)
{
    _x=x;
    _y=y;
}
double Cartesian::GetX()
{
    return _x;
}
double Cartesian::GetY()
{
    return _y;
}
