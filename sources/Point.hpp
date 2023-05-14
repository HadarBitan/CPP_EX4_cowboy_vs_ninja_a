#ifndef POINT_HPP
#define POINT_HPP

#pragma once

#include <iostream>
#include <string>


namespace ariel
{
    class Point
    {
        private:
            double x;
            double y;
        public:
            Point(double x_, double y_): x(x_), y(y_){}
            double distance(Point p);
            void print();
            Point moveToward(Point source, Point dest, double dist);
    };
}

#endif