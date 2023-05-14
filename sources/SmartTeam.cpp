#include <iostream>
#include "SmartTeam.hpp"
#include <string>
#include <vector>
#include "Character.hpp"


namespace ariel
{
        SmartTeam::SmartTeam(Character *leader){}
        void SmartTeam::add(Character *teamMember){}
        void SmartTeam::attack(SmartTeam *enemy){}
        int SmartTeam::stillAlive(){return 0;}
        string SmartTeam::print(){return "";}
        SmartTeam::~SmartTeam(){}
}
