// openGlBasicLearning.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdint.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef uint32_t COColor;
typedef uint8_t COChannel;
class Raster 
{
public:
	const int MAX_WIDTH = 1280;
	const int MAX_HEIGHT = 720;
	
	int width = 1;
	int height = 1;
	int colourDepth = 255;

	COColor **pPixels = NULL;

	Raster(int, int);
	Raster(COColor[],int,int,int);
	~Raster();
private :
	COColor ** makeV2ArrayfromWidhtHeight(int, int);
};

Raster::Raster(int myWidth, int myHeight)
{

	if (myWidth > 0 && myWidth < MAX_WIDTH)
	{
		this->width = myWidth;
	}
	if (myHeight > 0 && myHeight < MAX_HEIGHT)
	{
		this->height = myHeight;
	}
	pPixels = makeV2ArrayfromWidhtHeight(this->width, this->height);
}

Raster::Raster(COColor pixelArray[],int arraySize =0,int myWidth =0, int myHeight =0)
{
	if ( arraySize>0 && arraySize == myWidth * myHeight)
	{
		this->width = myWidth;
		this->height = myHeight;

		pPixels = makeV2ArrayfromWidhtHeight(this->width, this->height);

		cout<<"a testing"<<endl;

		for (int j = 0; j < height; j++)
		{
			for (int i = 0; i < width; i++)
			{
				pPixels[j][i] = pixelArray[j*(height - 1) + i];
				int a = pixelArray[i*(height - 1) + j];
				cout << hex << a;
				cout << " ";
			}
			cout << endl;
		}
		int a = 0x00FF03;
		cout << hex << a << endl;
		cout << hex << pixelArray[3]<<endl;
	}	
}

Raster::~Raster()
{
	if (!pPixels == NULL)
	{
		for (int i = 0; i < this->height; i++)
		{

			free(*(pPixels + i));

		}
	}
}

COColor** Raster::makeV2ArrayfromWidhtHeight(int myWidth, int myHeight)
{
	COColor **myV2Array = NULL;
	myV2Array = (COColor**)malloc(sizeof(COColor*)*myHeight);
	for (int i = 0; i < myHeight; i++)
	{
		*(myV2Array + i) = (COColor*)malloc(sizeof(int*)*myWidth);
	}

	for (int j = 0; j < myHeight; j++)
	{
		for (int i = 0; i < myWidth; i++)
		{
			myV2Array[j][i] = 0x000000;
		}
	}
	return myV2Array;
}

void RasterSaveToPPM(Raster);

int main()
{
	//Raster ad(3,4);
	COColor myRasterArr[] =
	{ 
		0x000000, 0x000001,
		0xffffff, 0x00FF03,
		0x000003, 0x000004
	};
	
	int _width = 2;
	int _height = 3;
	int _size = sizeof(myRasterArr) / sizeof(COColor);

	Raster ad(myRasterArr,_size, _width, _height);
	
	//RasterSaveToPPM(ad);
    return 0;
}

void RasterSaveToPPM(Raster ras/*, char* path*/)
{
	ofstream ppmFile;
	ppmFile.open("d:/test.ppm", ios::out);
	if (ppmFile.is_open())
	{
		string myStr;
		ppmFile << "P3\n";
		myStr = to_string(ras.width) + " " + to_string(ras.height)+" "+ to_string(ras.colourDepth)+"\n";
		ppmFile << myStr;
		myStr = "";
		for (int j=0; j < ras.height; j++)
		{
			for (int i=0; i < ras.width; i++)
			{
				COColor thisPixel = ras.pPixels[j][i];
				//printf("0x%x\n", thisPixel);
				COChannel red = (ras.pPixels[j][i] & 0xff0000)>>16;
				COChannel green = (ras.pPixels[j][i] & 0x00ff00)>>8;
				COChannel blue = ras.pPixels[j][i] & 0x0000ff;
				
				ppmFile << int(red);
				ppmFile << " ";
				ppmFile << int(green);
				ppmFile << " ";
				ppmFile << int(blue);
				ppmFile << " ";
			}
			ppmFile <<"\n";
		}
		ppmFile.close();
	}
}

