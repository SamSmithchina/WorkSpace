 /****************************************************************** 
*  
* Author：Sam Smith   wangbingzong@szkindom.com
* Time： 
* Version：V ... 
* Description：
*
* Editor：           
* Time：               
* Modification： 
*
**********************************************************************
* Copyright (c) $year$ ShenZhen Kindom Cor., Ltd. All rights reserved.
**********************************************************************/

/******************************************************************    
* Function:         
* Description:      
* Calls:             
* Called By:         
* Input:           
* Output:            
********************************************************************/

#pragma once
#ifndef STACK_H
#define STACK_H

#include "Include.h"
#include <vector>
#include <stdlib.h>

//#define STEP 20

//采用C++封装编程思想
//定义类class，面对对象。

class Localtion{
	//在迷宫当前位置的行号和列号
public:
	int y;
	int x;
};


class Stack :public Localtion
{
private:

	//迷宫设置存储步数size,
	int size;
	//迷宫实际存储步数length,
	int tag;
	//采用线性连续存储结构,由指针指示
	Localtion  *stackSpace;
	
public:
	Stack();
	void InitStack();
	void Push(Localtion inStack);
	Localtion GetTop();
	bool CheckLocaltionVaild(Localtion tempLocaltion);
	void ShowStack();
	Localtion Pop();
	~Stack();
};


#endif