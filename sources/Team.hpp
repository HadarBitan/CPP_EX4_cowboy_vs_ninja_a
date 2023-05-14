#ifndef TEAM_HPP
#define TEAM_HPP

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Point.hpp"
#include "Cowboy.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"

namespace ariel
{
    class Team
    {
        private:
            vector<Character> team;
            Character * leader;
        public:
            Team(Character *leader);
            void add(Character *teamMember);
            void attack(Team *enemy);
            int stillAlive();
            string print();
            ~Team();
    };
}

#endif