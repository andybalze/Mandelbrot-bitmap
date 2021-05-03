/*************************************************
* Function Title: main
*
* Summary: creates a file with the specified scheme
* Author: Weston Fausett
* Author A#: A02276419
* Inputs: number 1,2,3 for color scheme
* Outputs: success codes
****************Pseudocode*********************
Begin
  pull command line arguments
  create random number
  call mandelbrot generate 
End
*************************************************/
#include "mandelbrot.h"
#include <iostream>
#include <random>
#include <chrono>
#define BYTE unsigned char
int main (int argc, char *argv[]) {
  int scheme;
  //if no inputs
  if (argc == 1) {
    //seed with time
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    //number generator
    std::default_random_engine generator (seed);
    //set distribution
    std::uniform_int_distribution<int> distribution (1,3);
    //assign random number
    scheme = distribution(generator);
  } else if (argc == 2) {
    //assign command line input as scheme
    scheme = atoi(argv[1]);
  } else {
    //exit with exit failure
    return EXIT_FAILURE;
  }
  //create mandelbrot class
  myMandelbrot mandelbrot;
  //call render class
  mandelbrot.render(("mandelbrot_"+std::to_string(scheme)), scheme);
  //return 0
  return 0;
}
