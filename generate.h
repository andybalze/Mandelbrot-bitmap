#include "header.h"

class myGenerate {       
    public:
        myGenerate(){}
        myHeader header;
        void body(int width, int height, int xpos, int ypos, int scheme, BYTE* colorR, BYTE* colorG, BYTE* colorB);
    private:
        void palette(int value, BYTE* colorR, BYTE* colorG, BYTE* colorB, int scheme);
};