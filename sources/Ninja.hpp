#ifndef NINJA_HPP
#define NINJA_HPP

#pragma once

#include <iostream>
#include <string>
#include "Point.hpp"
#include "Character.hpp"


namespace ariel
{
    class Ninja : public Character
    {
        protected:
            int speed;
        public:
            Ninja(Point location, int hitPoint, string name, int speed): Character(location, hitPoint, name), speed(speed){}
            void move(Character *enemy);
            void slash(Character *enemy);
            int getSpeed();
            string print();
    };
}

#endif