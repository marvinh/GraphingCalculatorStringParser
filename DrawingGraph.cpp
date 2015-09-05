//
//  DrawingGraph.cpp
//  GraphingCalculator
//
//  Created by Marvin on 5/3/15.
//  Copyright (c) 2015 Marvin. All rights reserved.
//

#include "DrawingGraph.h"

sf::Vector2f RealWorldToWindow(Cartesian& c,PlaneSize& p)
{
    double xmin=p.Min.GetX();
    double xmax=p.Max.GetX();
    
    double ymin=p.Min.GetY();
    double ymax=p.Max.GetY();
    
    double x=c.GetX();
    double y=c.GetY();
    
    sf::Vector2f pos;
    pos.x= p.plane.left + p.plane.width * (x-xmin)/(xmax-xmin);
    pos.y= p.plane.top + p.plane.height * (ymax-y)/(ymax-ymin);
    
    return pos;
}
double increment(PlaneSize& p)
{
    double inc=(((p.Max.GetX()-p.Min.GetX())/p.plane.width)/1);
    return inc;
}
sf::VertexArray graphing(PlaneSize& p,std::vector<Cartesian>& c)
{
    sf::VertexArray g;
    for (int i=0; i<=c.size();i++){
        sf::Vector2f pos=RealWorldToWindow(c[i],p);
        g.append(sf::Vertex(pos,sf::Color::Cyan));
    }
    return g;
}
