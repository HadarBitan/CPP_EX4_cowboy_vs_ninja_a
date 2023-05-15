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
            Team2(const Team2&) = delete; 
            Team2& operator=(const Team2&) = delete;
            Team2& operator=(Team2&&) = delete;
            Team2(Team2&&) = delete;
            Team2(Character *leader);
            void add(Character *teamMember);
            void attack(Team2 *enemy);
            int stillAlive();
            string print();
            ~Team2();
    };
}

#endif