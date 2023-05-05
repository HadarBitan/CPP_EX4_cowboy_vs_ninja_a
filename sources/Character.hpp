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
        protected:
            Point location;
            int hitPoint;
            string name;
        public:
            Character(Point location, int hitPoint, string name);
            bool isAlive();
            double distance(Character &other);
            void hit(int numOfPoints);
            string getName();
            Point getLocation();
            virtual void print();
    };
}

#endif