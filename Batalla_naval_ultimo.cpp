#include <iostream>
#include <string>


//===Código de fondo de color===/


#define  BG_RED      "\x1B[41m"
#define  BG_WHITE    "\x1B[47m"
#define  BG_GRAY     "\x1B[48;2;176;174;174m"
#define  BG_BLUE     "\x1B[44m"
#define  RESET       "\x1b[0m"

using namespace std;

string Colors[] = {BG_RED, BG_WHITE, BG_GRAY, BG_BLUE};