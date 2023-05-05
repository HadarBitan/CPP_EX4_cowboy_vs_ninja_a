#ifndef YOUNGNINJA_HPP
#define YOUNGNINJA_HPP

#pragma once

#include <iostream>
#include <string>
#include "Ninja.hpp"


namespace ariel
{
    class YoungNinja : protected Ninja
    {
        YoungNinja(Point location, string name): Ninja(location, 100, name, 14){}
    };
}

#endif