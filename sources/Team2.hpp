#ifndef TEAM2_HPP
#define TEAM2_HPP

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Point.hpp"
#include "Character.hpp"

namespace ariel
{
    class Team2
    {
        private:
            vector<Character> team;
            Character * leader;
        public:
            Team2(Character &leader);
            void add(Character &teamMember);
            void attack(Team2 &enemy);
            int stillAlive();
            void print();
            ~Team2();
    };
}

#endif