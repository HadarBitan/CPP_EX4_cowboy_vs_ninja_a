#ifndef OLDNINJA_HPP
#define OLDNINJA_HPP

#pragma once

#include <iostream>
#include <string>
#include "Ninja.hpp"


namespace ariel
{
    class OldNinja : protected Ninja
    {
        OldNinja(Point location, string name): Ninja(location, 150, name, 8){}
    };
}

#endif