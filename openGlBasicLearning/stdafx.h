// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"
#include "stdint.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <string>
#include<iomanip>
#include <math.h>

typedef uint32_t TCOColor;
typedef uint8_t TCOChannel;

using namespace std;

//查找数组长度
#define GET_ARRAY_LEN(array,len){len = (sizeof (array))/(sizeof (array[0]));}
// TODO: reference additional headers your program requires here
