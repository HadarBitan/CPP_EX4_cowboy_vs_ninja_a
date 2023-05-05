#include <iostream>
#include <string>
#include "Point.hpp"
#include "Character.hpp"

using namespace std;

namespace ariel
{
        Character::Character(Point location, int hitPoint, string name):location(location), hitPoint(hitPoint), name(name){}
        bool Character::isAlive(){return false;}
        double Character::distance(Character &other){return 0.0;}
        void Character::hit(int numOfPoints){}
        string Character::getName(){return "";}
        Point Character::getLocation(){return Point(0,0);}
        void Character::print(){}
}