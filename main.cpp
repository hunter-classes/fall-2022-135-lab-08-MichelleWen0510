#include <iostream>
#include <string>
#include "funcs.h"
#include "imageio.h"

int main()
{
	std::string input = "image1.pgm";
        int img[MAX_H][MAX_W];
        int h,w;
        readImage(input,img,h,w);

        int out[MAX_H][MAX_W];
        for(int row=0;row<h;row++)
        {
                for(int col=0;col<w;col++)
                {
                        out[row][col]=invert(img[row][col]);
                }
        }
        writeImage("taskA.pgm",out,h,w);

	for(int row1=0;row1<h;row1++)
        {
                for(int col1=0;col1<w;col1++)
                {
			if(col1>=(w/2))
			{
                        	out[row1][col1]=invert(img[row1][col1]);
			} else {
				out[row1][col1]=img[row1][col1];
			}
                }
        }
        writeImage("taskB.pgm",out,h,w);

	for(int row2=0;row2<h;row2++)
        {
                for(int col2=0;col2<w;col2++)
                {
                        if(row2<=h/4 || row2>=(3*(h/4)) || col2<=h/4 || col2>=(3*(h/4)))
                        {
                                out[row2][col2]=img[row2][col2];
                        } else {
                                out[row2][col2]=255;
                        }
                }
        }
        writeImage("taskC.pgm",out,h,w);

	for(int row3=0;row3<h;row3++)
        {
                for(int col3=0;col3<w;col3++)
                {
                        if((row3==h/4 && col3>w/4 && col3<3*(w*4))|| 
			(row3==3*(h/4) && col3>w/4 && col3<3*(w*4))|| 
			(col3==w/4  && row3>h/4 && row3<3*(h*4))|| 
			(col3==3*(w/4)&& row3>h/4 && row3<3*(h*4) ))
                        {
                                out[row3][col3]=255;
                        } else {
                                out[row3][col3]=img[row3][col3];
                        }
                }
        }
        writeImage("taskD.pgm",out,h,w);
	
	for(int row4=0;row4<h;row4++)
        {
                for(int col4=0;col4<w;col4++)
                {
                        out[row4][col4]=img[row4][col4];
			out[row4+1][col4]=img[row4][col4];
			out[row4][col4+1]=img[row4][col4];
			out[row4+1][col4+1]=img[row4][col4];
                }
        }
        writeImage("taskE.pgm",out,h,w);
	int color;
	for(int row5=0;row5<h;row5+=2)
        {
                for(int col5=0;col5<w;col5+=2)
                {
			color=pixel(img[row5][col5],img[row5+1][col5],img[row5][col5+1],img[row5+1][col5+1]);
			out[row5][col5]=color;
                        out[row5+1][col5]=color;
                        out[row5][col5+1]=color;
                        out[row5+1][col5+1]=color;
                        
                }
        }
        writeImage("taskF.pgm",out,h,w);
}
