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
	// todo : test the new Color class
	COColor myCorour1 = Color::makeCOColor((COChanelByte)0xff, (COChanelByte)0x11, (COChanelByte)0x22, (COChanelByte)0x33);
	COColor myCorour3 = Color::multiply(myCorour1, 0.5f);
	cout << hex <<(int) myCorour3.a << endl;
	cout << hex << (int) myCorour3.r << endl;
	cout << hex << (int) myCorour3.g << endl;
	cout << hex << (int) myCorour3.b << endl;

	cout << (int)Color::getByte(0.5f) << endl;


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


