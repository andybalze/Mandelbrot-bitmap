#include "header.h"
/*************************************************
* Function Title: mandelbrot.generate_header()
*
* Summary: calls both header functions dip and bitmap
* Author: Weston Fausett
* Author A#: A02276419
* Inputs: none
* Outputs: none
****************Pseudocode*********************
Begin
  mandelbrot.generate.header.dip()
  mandelbrot.generate.header.bitmapfile()
End
*************************************************/
myHeader::myHeader(void) {
    myHeader::dip();
    myHeader::bitmapfile();
}

/*************************************************
* Function Title: mandelbrot.generate_header_dip()
*
* Summary: holds an STL array for the dip header
* Author: Weston Fausett
* Author A#: A02276419
* Inputs: none
* Outputs: none
****************Pseudocode*********************
Begin
  4 bytes size (12)
  2 bytes width ()
  2 bytes height ()
  2 bytes color planes (1)
  2 bytes bits per pixel (24)
End

*************************************************/
void myHeader::dip(void) {
  std::array<BYTE, 40> newdipHeader = {
    0x28,0x00,0x00,0x00, //size 
    0x40,0x1F,0x00,0x00, //width
    0xDB,0x11,0x00,0x00,//height
    0x01,0x00,//panes
    0x18,0x00,//bits per pixel
    0x00,0x00,0x00,0x00,//compression method
    0x76,0xf3,0x89,0x06,//4 bytes output size of file  (file size: 109,704,054)
    0x00,0x00,0x00,0x00,//the horizontal resolution of the image. (pixel per metre, signed integer)
    0x00,0x00,0x00,0x00,//the vertical resolution of the image. (pixel per metre, signed integer)
    0x00,0x00,0x00,0x00,//colros in pallette
    0x00,0x00,0x00,0x00//important colors used
  }; 
  dipHeader = newdipHeader;
}

/*************************************************
* Function Title: mandelbrot.generate_header_bitmapfile()
*
* Summary: holds an STL array for the bitmap file header
* Author: Weston Fausett
* Author A#: A02276419
* Inputs: none
* Outputs: none
****************Pseudocode*********************
Begin
  2 bytes are BM (0x42 0x4D)
  4 bytes output size of file  (file size: 109,704,054)
  2 bytes of zeros
  2 bytes of zeros
  4 bytes for the offset (starting address of file) (26)
End
BYTES header[] = {}
*************************************************/
void myHeader::bitmapfile(void) {
  std::array<BYTE, 14> newbitHeader = {
    0x42,0x4D,//2 bytes are BM (0x42 0x4D)
    0x40,0xf3,0x89,0x06,//4 bytes output size of file  (file size: 109,704,054)
    0x00,0x00,//2 bytes of zeros
    0x00,0x00,//2 bytes of zeros
    0x36,0x00,0x00,0x00//4 bytes for the offset (starting address of file) (26){54}
  };
  bitHeader = newbitHeader;
}