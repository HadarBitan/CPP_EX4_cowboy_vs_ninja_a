#ifndef YOUNGNINJA_HPP
#define YOUNGNINJA_HPP

#pragma once

#include <iostream>
#include <string>
#include "Ninja.hpp"


namespace ariel
{
    class YoungNinja : public Ninja
    {
        public:
            YoungNinja(string name, Point location): Ninja(location, 100, name, 14){}
    };
}

#endif