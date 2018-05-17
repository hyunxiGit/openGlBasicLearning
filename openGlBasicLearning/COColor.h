#pragma once
#include "stdafx.h"

typedef uint32_t COColorByte;
typedef uint8_t  COChanelByte;
class COColor
{
public:
	
	//int Colour
	COColorByte    colorByte;
	COColorByte*   colorptr = nullptr;
	COChanelByte*  aPtr = nullptr;
	COChanelByte*  rPtr = nullptr;
	COChanelByte*  gPtr = nullptr;
	COChanelByte*  bPtr = nullptr;
	
	COColor(COColorByte);

	//������캯���õ�ʱ����Ҫ��֤���鳤��Ϊ4��˳��ΪARGB
	COColor(COChanelByte*);

	COColor operator+ (COColor);
	COColor operator* (float);

	float* COColorToFloat();
	COColorByte floatToByte(float*);


	void print(short mode);
	//0 : 0xFFFFFF (1,1,1,1)
	//1 :  0xFFFFFF (255,255,255,255)
	//2 : 0xFFFFFF <Color Address> <A Address, R Address, G Address, B Address,>
private:
	void initPtr();
};