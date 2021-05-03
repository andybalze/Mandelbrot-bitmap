#include <string>
#include "generate.h"
#define BYTE unsigned char
#pragma once

class myMandelbrot {
    public:
        myMandelbrot(){}
        bool render(std::string fileName, int scheme);
        myGenerate generate;
};