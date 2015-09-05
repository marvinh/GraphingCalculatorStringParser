
#include <SFML/Graphics.hpp>
#include <iostream>

#include "PlaneSize.h"
#include "Cartesian.h"
#include "DrawingGraph.h"
#include "Syard.h"
using namespace std;


int main()
{
    ///////////Setting default plane size and axis///////////////
    PlaneSize DefaultPlane;
    DefaultPlane.Max.SetXY(10,10);
    DefaultPlane.Min.SetXY(-10,-10);
    DefaultPlane.plane.width=800;
    DefaultPlane.plane.height=600;
    Cartesian verticieX[2],verticieY[2];
    verticieX[0].SetXY(-10,0);
    verticieX[1].SetXY(10, 0);
    verticieY[0].SetXY(0,-10);
    verticieY[1].SetXY(0,10);
    sf::Vertex axis[] =
    {
        sf::Vertex(RealWorldToWindow(verticieX[0],DefaultPlane)),
        sf::Vertex(RealWorldToWindow(verticieX[1],DefaultPlane)),
        sf::Vertex(RealWorldToWindow(verticieY[0],DefaultPlane)),
        sf::Vertex(RealWorldToWindow(verticieY[1],DefaultPlane))
    };
    /////////////////////////////////////////////////////////////
    
    cout<<"Press G key on the window to input equation."<<endl;
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    window.setVerticalSyncEnabled(true);
    
    /////////////////////////
    std::vector<Cartesian> c;
    std::string input;
    sf::VertexArray v;
    ///////////////////////
    
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            if(event.type==sf::Event::KeyPressed &&event.key.code==sf::Keyboard::G)
            {
                ///input event///
                cout<<"y=";
                getline(cin,input);
                
                cout<<"\nInfix from buffer:"<<input<<endl;
                try{
                    queue<Token*>infix=InFix(input);
                    queue<Token*>post=InFixToPostFix(infix);
                    PostPrint(post);
                    Cartesian e;
                    double inc=increment(DefaultPlane);
                    double x=0;
                    for(x=-10;x<10;x+=inc)
                    {
                        double eval=Evaluation(post,x);
                        e.SetXY(x,eval);
                        c.push_back(e);
                        
                    }
                    v.clear();
                    v=graphing(DefaultPlane, c);
                    c.clear();
                }catch(int i)
                {
                    switch (i) {
                        case UNKNOWN_INPUT:
                            cout<<"\nUnkown input or lack of seperators.\n(eg:sinx should be sin x)\n";
                            break;
                        case MISMATCHED_PARAN:
                            cout<<"\nMismatched paranthesis...\n";
                            break;
                        case MISMATHED_OP_OR_FUNC:
                            cout<<"\nMismatched operator or function...\n";
                            break;
                        case -1:
                            cout<<"\nEmpty...";
                            break;
                        default:
                            cout<<"\ndefault error\n";
                            break;
                    }
                    
                    cout<<"Try again press G key on the window.";
                }
                
            }
        }
        // Clear screen
        window.clear();
        window.draw(axis,4,sf::Lines);
        window.draw(v);
        window.display();
    }

    return EXIT_SUCCESS;
}
