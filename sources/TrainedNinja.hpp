#ifndef TRAINEDNINJA_HPP
#define TRAINEDNINJA_HPP

#pragma once

#include <iostream>
#include <string>
#include "Ninja.hpp"


namespace ariel
{
    class TrainedNinja : protected Ninja
    {
        public:
            TrainedNinja(string name, Point location): Ninja(location, 120, name, 12){}
    };
}

#endif