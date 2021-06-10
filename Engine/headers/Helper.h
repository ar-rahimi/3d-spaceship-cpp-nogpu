//
// Created by Ahmad Rahimi on 2/21/18.
//

#ifndef SHOOTER_HELPER_H
#define SHOOTER_HELPER_H

#include <math.h>

static class Helper{
public:
    static float GetRadians(float degrees);
    static float GetDegrees(float radians);
};

float Helper::GetRadians(float degrees) {
    return degrees * M_PI_2 / 180;
}

float Helper::GetDegrees(float radians) {
    return radians * 180 / M_PI_2;
}


#endif //SHOOTER_HELPER_H
