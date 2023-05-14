#include <iostream>
#include <string>
#include "Point.hpp"
#include "Cowboy.hpp"


namespace ariel
{
    void Cowboy::shoot(Character *enemy){}
    bool Cowboy::hasboolets(){return this->numOfBoolets > 0;}
    void Cowboy::reload(){}
    int Cowboy::getNumOfBoolets(){return this->numOfBoolets;}
    string Cowboy::print(){return "";}
}