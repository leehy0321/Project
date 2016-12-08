//total game header

#include <stdio.h>
#include <time.h> // random
#include <stdlib.h>

#include <termios.h>  // kbhit
#include <unistd.h>

#define SHAPE_C 1  // "●"  circle
#define SHAPE_R 2  // "■"  rectangle
#define SHAPE_S 3  // "★"  star
#define SHAPE_H 4  // "♥"  heart
#define SHAPE_T 5  // "▲"  triangle

#define SHAPE_C_ -1  // "○"  other color
#define SHAPE_R_ -2  // "□"
#define SHAPE_S_ -3  // "☆"  
#define SHAPE_H_ -4  // "△"
#define SHAPE_T_ -5  // "♡"

#define SHAPE_C_E 11  // enter position -> other color
#define SHAPE_R_E 12  // 
#define SHAPE_S_E 13  //   
#define SHAPE_H_E 14  // 
#define SHAPE_T_E 15  // 

#define WALL -10 // "▦"  wall 

#define B_SIZE_X 11  // board size x ( game size x )
#define B_SIZE_Y 11  // board size y ( game size y )

#define S_POSIT_X 10  // start position x
#define S_POSIT_Y 5 // start position y
