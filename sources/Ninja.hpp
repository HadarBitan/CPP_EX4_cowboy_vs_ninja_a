#ifndef NINJA_HPP
#define NINJA_HPP

#pragma once

#include <iostream>
#include <string>
#include <utility>
#include "Point.hpp"
#include "Character.hpp"


namespace ariel
{
    class Ninja : public Character
    {
        public:
            int speed;
            Ninja(Point location, int hitPoint, string name, int speed): Character(location, hitPoint, std::move(name)), speed(speed){}
            void move(Character *enemy);
            void slash(Character *enemy);
            int getSpeed();
            string print() override;
    };
}

#endif