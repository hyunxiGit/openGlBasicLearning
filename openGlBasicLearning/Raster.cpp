
#include "stdafx.h"
#include "Raster.h"

using namespace std;
Raster::Raster(int myWidth, int myHeight) 
	:pPixels ( nullptr )
{
	if (checkSize(myWidth, myHeight))
	{
		width = myWidth;
		height = myHeight;
		arraySize = myWidth * myHeight;
		makePixels(width, height);
	}
}

Raster::Raster(COColor pixelArray[], int myWidth = 0, int myHeight = 0)
{
	if (checkSize(myWidth, myHeight))
	{
		width = myWidth;
		height = myHeight;
		arraySize = myWidth * myHeight;

		makePixels(width, height);
		setPixels(pixelArray, width, height);
	}
}

Raster::~Raster()
{
	freePPixels();
}

void Raster::makePixels(int myWidth, int myHeight)
{
	freePPixels();
	if (checkSize(myWidth, myHeight))
	{
		width = myWidth;
		height = myHeight;
		arraySize = width * height;

		pPixels = (COColor**)malloc(sizeof(COColor*)*height);
		for (int i = 0; i < height; i++)
		{
			*(pPixels + i) = (COColor*)malloc(sizeof(int*)*width);
		}

		//initialize the pixel tobe defaultValue
		for (int j = 0; j < height; j++)
		{
			for (int i = 0; i < width; i++)
			{
				pPixels[j][i] = DEFAULT_VALUE;
			}
		}
	}
}


void Raster::setPixels(COColor setPixels[], int myWidth, int myHeight)
{
	if (this->checkSize(myWidth, myHeight))
	{
		for (int j = 0; j < height; j++)
		{
			for (int i = 0; i < width; i++)
			{
				pPixels[j][i] = setPixels[j*width + i];
			}
		}
	}
}

void Raster::freePPixels()
{
	if (!(pPixels == NULL))
	{
		for (int i = 0; i < this->height; i++)
		{

			free(*(pPixels + i));

		}
	}
}

bool Raster::checkSize(int myWidth, int myHeight)
{
	bool success = false;
	if (myWidth > 0 && myHeight > 0)
	{

		success = true;

	}
	return (success);
}

bool Raster::saveToFile(char *_path)
{
	//check if file exist
	//ifstream infile(_path);

	ofstream ppmFile;
	ppmFile.open(/*"d:/test.ppm"*/_path, ios::out);
	if (ppmFile.is_open())
	{
		string myStr;
		ppmFile << "P3\n";
		myStr = to_string(width) + " " + to_string(height) + " " + to_string(colourDepth) + "\n";
		ppmFile << myStr;
		myStr = "";
		for (int j = 0; j < height; j++)
		{
			for (int i = 0; i < width; i++)
			{
				COColor thisPixel = pPixels[j][i];
				COChannel red   = (pPixels[j][i] & 0xff0000) >> 16;
				COChannel green = (pPixels[j][i] & 0x00ff00) >> 8;
				COChannel blue  =  pPixels[j][i] & 0x0000ff;

				ppmFile << int(red);
				ppmFile << " ";
				ppmFile << int(green);
				ppmFile << " ";
				ppmFile << int(blue);
				ppmFile << " ";
			}
			ppmFile << "\n";
		}
		ppmFile.close();
	}
	return (true);
}


void Raster::print()
{
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i <width; i++)
		{
			//cout << this->pPixels[j][i];
			printf("0x%06x\n", pPixels[j][i]);
		}
		cout << endl;
	}
}