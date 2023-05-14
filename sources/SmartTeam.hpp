#ifndef SMARTTEAM_HPP
#define SMARTTEAM_HPP

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Point.hpp"
#include "Character.hpp"

namespace ariel
{
    class SmartTeam
    {
        private:
            vector<Character> team;
            Character * leader;
        public:
            SmartTeam(Character *leader);
            void add(Character *teamMember);
            void attack(SmartTeam *enemy);
            int stillAlive();
            string print();
            ~SmartTeam();
    };
}

#endif