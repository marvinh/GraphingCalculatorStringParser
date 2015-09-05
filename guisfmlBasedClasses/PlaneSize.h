//
//  PlaneSize.h
//  GraphingCalculator
//
//  Created by Marvin on 4/28/15.
//  Copyright (c) 2015 Marvin. All rights reserved.
//

#ifndef GraphingCalculator_PlaneSize_h
#define GraphingCalculator_PlaneSize_h

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Cartesian.h"
//struct for plane setting max min and min
struct PlaneSize {
public:
    sf::FloatRect plane;//window plane
    Cartesian Max;//to set max in real world coords
    Cartesian Min;//to set min in real world coords
};
#endif
