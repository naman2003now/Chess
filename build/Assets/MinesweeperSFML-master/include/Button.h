#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Button{
public:
    sf::ConvexShape shape;
    Button(sf::Vector2f size, float radius);
    ~Button();
};