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

	COColor a(0x11111111);
	COColor b(0x22222222);
	//现在这个新建出来的newColor在栈上,而且没有拷贝函数,所以会出错
	//todo 写一个copy 函数
	//todo 新写一个结构体类,看看结构体对齐
	COColor myNewColor = a + b;
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

