#include "generate.h"
#define MAX_ITERATION 1000
/*************************************************
* Function Title: body;
*
* Summary: bitmap generator
* Author: Weston Fausett
* Author A#: A02276419
* Inputs: color schemes values
* Outputs: none
****************Pseudocode*********************
Begin
  for each pixel (Px, Py) on the screen do
      x0 := scaled x coordinate of pixel (scaled to lie in the Mandelbrot X scale (-2.5, 1))
      y0 := scaled y coordinate of pixel (scaled to lie in the Mandelbrot Y scale (-1, 1))
      x := 0.0
      y := 0.0
      iteration := 0
      max_iteration := 1000
      while (x*x + y*y ≤ 2*2 AND iteration < max_iteration) do
          xtemp := x*x - y*y + x0
          y := 2*x*y + y0
          x := xtemp
          iteration := iteration + 1
      
      color := palette[iteration]
      mandelbrot.plot(Px, Py, color)
      //plot[Px][Py][{0,blue;1,green;2,red}]
End
*************************************************/
void myGenerate::body(int width, int height, int i, int j, int scheme, BYTE* colorR, BYTE* colorG, BYTE* colorB) {
    double x = 0.0;
    double y = 0.0;
    double x0 = (((double)i/((double)width-1))*(1.0 - -2.5))-2.5;//scale the pixel width
    double y0 = (((double)j/ ((double)height-1)) *(1.0 - -1.0))-1.0;//scale the pxel height
    int iterator = 0;
    while ((x*x+y*y<=2*2) && (iterator < MAX_ITERATION)) {
        double xtemp = x*x - y*y + x0;
        y= 2*x*y +y0;
        x= xtemp;
        iterator++;
    }
    //pass RBG by value and pass the iterator
    palette(iterator,colorR,colorG, colorB, scheme);
}

/*************************************************
* Function Title: palette;
*
* Summary: pallette
* Author: Weston Fausett
* Author A#: A02276419
* Inputs: value calculated
* Outputs: Color values for location
****************Pseudocode*********************
Begin
    sets color values based on inputs
End
*************************************************/
void myGenerate::palette(int value, BYTE* colorR, BYTE* colorG, BYTE* colorB, int scheme) {
    switch (scheme) {
        //If scheme is RED
        case 1:
            if (value == 1000) {*colorR = 0x00;}
                else if (value > 900) {*colorR = 0x11;}
                else if (value > 700) {*colorR = 0x33;}
                else if (value > 500) {*colorR = 0x55;}
                else if (value > 300) {*colorR = 0x77;}
                else if (value > 200) {*colorR = 0x99;}
                else if (value > 100) {*colorR = 0xAA;}
                else if (value > 50) {*colorR = 0xBB;}
                else if (value > 40) {*colorR = 0xCC;}
                else if (value > 30) {*colorR = 0xDD;}
                else if (value > 20) {*colorR = 0xEE;}
                else if (value > 10) {*colorR = 0xFF;}
                else {*colorR = 0xAA;}
            break; 
        //If scheme is BLUE
        case 2:
            if (value == 1000) {*colorB = 0x00;}
                else if (value > 900) {*colorB = 0x11;}
                else if (value > 700) {*colorB = 0x33;}
                else if (value > 500) {*colorB = 0x55;}
                else if (value > 300) {*colorB = 0x77;}
                else if (value > 200) {*colorB = 0x99;}
                else if (value > 100) {*colorB = 0xAA;}
                else if (value > 50) {*colorB = 0xBB;}
                else if (value > 40) {*colorB = 0xCC;}
                else if (value > 30) {*colorB = 0xDD;}
                else if (value > 20) {*colorB = 0xEE;}
                else if (value > 10) {*colorB = 0xFF;}
                else {*colorB = 0xAA;}
            break;
        //If scheme is Green
        case 3:
            if (value == 1000) {*colorG = 0x00;}
                else if (value > 900) {*colorG = 0x11;}
                else if (value > 700) {*colorG = 0x33;}
                else if (value > 500) {*colorG = 0x55;}
                else if (value > 300) {*colorG = 0x77;}
                else if (value > 200) {*colorG = 0x99;}
                else if (value > 100) {*colorG = 0xAA;}
                else if (value > 50) {*colorG = 0xBB;}
                else if (value > 40) {*colorG = 0xCC;}
                else if (value > 30) {*colorG = 0xDD;}
                else if (value > 20) {*colorG = 0xEE;}
                else if (value > 10) {*colorG = 0xFF;}
                else {*colorG = 0xAA;}
            break;
        default:
        break;
    }
}