#include <iostream>
#include <string>
#include "funcs.h"

int invert(int num)
{
	return 255-num;
}

int pixel(int a, int b, int c, int d)
{
	return int((a+b+c+d)/4);
}
