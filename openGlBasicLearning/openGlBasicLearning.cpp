// openGlBasicLearning.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "COVector.h"
#include "CORaster.h"
#include "COTriangle.h"
#include "RasterDraw.h"
#include "COColor.h"


//void RasterSaveToPPM(Raster);
int main()
{
	//COColor myColor(0xFF112233);

	COColor myFullColor(0xFFFFFFFF);
	COColor myNewColor = myFullColor * 0.5f;
	myNewColor.print(0);


	system("pause");
	/*
	COVector2 tri[3] = { COVector2(15.0f, 5.0f), COVector2(5.0f, 15.0f), COVector2(5.0f, 5.0f)};
	COTriangle myTri(tri);

	COVector2 a(0.1, 1.1);
	COVector2 *vptr = &a;
	
	int _width = 32;
	int _height = 32;

	CORaster ad(_width, _height);

	RasterDraw drawer;
	drawer.drawTriangle(&ad, &myTri);

	char d[] = "d:/test.ppm";
	ad.saveToFile(d);
    return 0;
	*/
}


