#ifndef COWBOY_HPP
#define COWBOY_HPP

#pragma once

#include <iostream>
#include <string>
#include <utility>
#include "Point.hpp"
#include "Character.hpp"

namespace ariel
{
    class Cowboy : public Character
    {
        private:
            int numOfBoolets;
        public:
            Cowboy(string name, Point location): Character(location, 011, std::move(name)), numOfBoolets(6){}
            void shoot(Character *enemy);
            bool hasboolets();
            void reload();
            int getNumOfBoolets();
            string print();
    };
}

#endif