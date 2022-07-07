#pragma once 
#include <SFML/Graphics.hpp>
using namespace sf;
sf::View view;

void move_cam(float x, float y){
    if(x<200){
        x=200;
    }

     if(x>425){
        x=425;
    }

     if(y<150){
        y=150;
    }

     if(y>600){
        y=600;
    }

    view.setCenter(x+10, y+10);
    

}