#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#pragma once

#include <iostream>
#include <string>
#include "Point.hpp"

using namespace std;

namespace ariel
{
    class Character
    {
        public:
            Point location;
            int hitPoint;
            string name;
            Character(Point location, int hitPoint, string name);
            Character(const Character&) = delete; 
            Character& operator=(const Character&) = delete;
            Character& operator=(Character&&) = delete;
            Character(Character&&) = delete;
            bool isAlive();
            double distance(Character &other);
            void hit(int numOfPoints);
            string getName();
            Point getLocation();
            virtual string print() = 0;
            int getHitPoint();
            virtual ~Character() = default;
    };
}

#endif