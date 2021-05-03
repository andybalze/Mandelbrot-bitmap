#include <array>
#define BYTE unsigned char
#pragma once
class myHeader{
    public:
        std::array<BYTE, 14> bitHeader;
        std::array<BYTE, 40> dipHeader;
        myHeader(void);
        void dip(void);
        void bitmapfile(void);
};