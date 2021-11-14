#include "Button.h"
#include <math.h>

float length(sf::Vector2f vector){
    long double x = pow(vector.x, 2);
    long double y = pow(vector.y, 2);
    return sqrt(x + y);
}

sf::Vector2f normalize(sf::Vector2f vector){
    return vector*(1/length(vector));
}

float getCurrentAngle(sf::Vector2f vector){
    if(vector.x < 0) return 3.1415926f + atan(vector.y/vector.x); //correction for arc tan range being only from pi/2 to -pi/2
    return atan(vector.y/vector.x);
}

sf::Vector2f translate(sf::Vector2f vector, sf::Vector2f origin){
    float x = vector.x - origin.x;
    float y = vector.y - origin.y;
    return sf::Vector2f(x, y);
}

sf::Vector2f rotate(sf::Vector2f vector, sf::Vector2f origin, float angle){
    sf::Vector2f finalVector;
    float radsAngle = angle*(3.1415926f/180.0f);
    sf::Vector2f tvector = translate(vector, origin);
    float currentAngle = getCurrentAngle(normalize(tvector));
    finalVector = sf::Vector2f(cos(radsAngle + currentAngle), sin(radsAngle + currentAngle))*length(tvector);
    return translate(finalVector, -origin);
}

Button::Button(sf::Vector2f size, float radius){
    this->shape.setPointCount(100);
    size = size/2.0f;

    sf::Vector2f origin = sf::Vector2f((size.x*(100.0f - radius))/100.0f, (size.y*(100.0f - radius))/100.0f);
    sf::Vector2f point = origin + sf::Vector2f(radius, 0);
    for(int i = 0; i < 25; i++){
        point = rotate(point, origin, 360.0f/100.0f);
        shape.setPoint(i, point);
    }

    origin = sf::Vector2f(-(size.x*(100.0f - radius))/100.0f, (size.y*(100.0f - radius))/100.0f);
    point = origin + sf::Vector2f(0, radius);
    for(int i = 25; i < 50; i++){
        point = rotate(point, origin, 360.0f/100.0f);
        shape.setPoint(i, point);
    }

    origin = sf::Vector2f(-(size.x*(100.0f - radius))/100.0f, -(size.y*(100.0f - radius))/100.0f);
    point = origin + sf::Vector2f(-radius, 0);
    for(int i = 50; i < 75; i++){
        point = rotate(point, origin, 360.0f/100.0f);
        shape.setPoint(i, point);
    }

    origin = sf::Vector2f((size.x*(100.0f - radius))/100.0f, -(size.y*(100.0f - radius))/100.0f);
    point = origin + sf::Vector2f(0, -radius);
    for(int i = 75; i < 100; i++){
        point = rotate(point, origin, 360.0f/100.0f);
        shape.setPoint(i, point);
    }

    this->shape.setOutlineColor(sf::Color(4, 7 , 40));
    this->shape.setOutlineThickness(-3.5);
}

Button::~Button(){

}
