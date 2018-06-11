// openGlBasicLearning.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "COVector.h"
#include "CORaster.h"
#include "COTriangle.h"
#include "RasterDraw.h"
#include "COColor.h"
#include "COMatrix.h"


//void RasterSaveToPPM(Raster);
int main()
{
	double pi = 3.1415926535897932 ; 

	COVector3 myV = Vector::makeCOVector3(1.0f, 0.0f, 0.0f);
	cout << "before transfer : ";
	
	Vector::print(myV);
	myV = Matrix::rotateZ4(myV, pi/2);
	cout << "after transfer : ";
	Vector::print(myV);


	system("pause");

	return 0;
	
}


