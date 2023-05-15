#ifndef OLDNINJA_HPP
#define OLDNINJA_HPP

#pragma once

#include <iostream>
#include <string>
#include <utility>
#include "Ninja.hpp"

constexpr int hitPointOld = 150;
constexpr int SpeedOld = 8;

namespace ariel
{
    class OldNinja : public Ninja
    {
        public:
            OldNinja(string name, Point location): Ninja(location, hitPointOld, std::move(name), SpeedOld){}
    };
}

#endif