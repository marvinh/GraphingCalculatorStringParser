//
//  Cartesian.h
//  GraphingCalculator
//
//  Created by Marvin on 4/28/15.
//  Copyright (c) 2015 Marvin. All rights reserved.
//

#ifndef __GraphingCalculator__Cartesian__
#define __GraphingCalculator__Cartesian__

#include <stdio.h>
#include <SFML/Graphics.hpp>

//struct for real world coordinates
struct Cartesian {
public:
    Cartesian ();
    Cartesian (double x,double y);
    void SetX(double x);
    void SetY(double y);
    void SetXY(double x, double y);
    double GetX();
    double GetY();
private:
    double _x;
    double _y;
};

#endif /* defined(__GraphingCalculator__Cartesian__) */
