#ifndef YOUNGNINJA_HPP
#define YOUNGNINJA_HPP

#pragma once

#include <iostream>
#include <string>
#include <utility>
#include "Ninja.hpp"


namespace ariel
{
    class YoungNinja : public Ninja
    {
        public:
            YoungNinja(string name, Point location): Ninja(location, 100/*hit points*/, std::move(name), 14/*the ninja speed*/){}
    };
}

#endif