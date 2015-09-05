//
//  DrawingGraph.h
//  GraphingCalculator
//
//  Created by Marvin on 5/3/15.
//  Copyright (c) 2015 Marvin. All rights reserved.
//

#ifndef __GraphingCalculator__DrawingGraph__
#define __GraphingCalculator__DrawingGraph__

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "PlaneSize.h"
#include "Cartesian.h"
#include <iostream>


//convert to window coords and proper increments
sf::Vector2f RealWorldToWindow(Cartesian& c,PlaneSize& p);
double increment(PlaneSize& p);
//
//gets vector of cartesian coordinates and draws
sf::VertexArray graphing(PlaneSize& p,std::vector<Cartesian>& c);


#endif /* defined(__GraphingCalculator__DrawingGraph__) */
