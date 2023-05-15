#ifndef COWBOY_HPP
#define COWBOY_HPP

#pragma once

#include <iostream>
#include <string>
#include <utility>
#include "Point.hpp"
#include "Character.hpp"

constexpr int hitPointCowboy = 110;
constexpr int bullets = 6;

namespace ariel
{
    class Cowboy : public Character
    {
        private:
            int numOfBoolets;
        public:
            Cowboy(string name, Point location): Character(location, hitPointCowboy, std::move(name)), numOfBoolets(bullets){}
            void shoot(Character *enemy);
            bool hasboolets();
            void reload();
            int getNumOfBoolets();
            string print() override;
    };
}

#endif