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
* ********************************************************************
* Copyright (c) $year$ ShenZhen Kindom Cor., Ltd. All rights reserved.
* *******************************************************************/

/******************************************************************
* Function:
* Description:
* Calls:
* Called By:
* Input:
* Output:
* *******************************************************************/



#include "Stack.h"
#include<iomanip>
#include<stdlib.h>
using namespace std;
//构造函数
Stack::Stack()
{
	tag = -1;	//	-1
	size = 20;
	//cout<<"构造函数"<<endl;
	stackSpace = (Localtion*)malloc(sizeof(Localtion) * size);
	//stackSpace = new Localtion[size];
	if (stackSpace == NULL)
	{
		cout << "malloc() fail" << endl;
	}

}

void Stack::InitStack()
{
	tag = -1;	//	-1
	size = 20;
	//cout<<"构造函数"<<endl;
	stackSpace = (Localtion*)malloc(sizeof(Localtion) * size);
	if (stackSpace == NULL)
	{
		cout << "malloc() fail" << endl;
	}

}

//Pop() ,弹栈函数
Localtion Stack::Pop()
{
	Localtion temp;
	if (tag >= 0)
	{
	//	cout << endl << "pop ( " << stackSpace[tag].x << " , " << stackSpace[tag].y << "  )" << "\t";
		return(stackSpace[tag--]);
	}
	else if (tag == -1)
	{
		cout << "worry! Stack is empty!" << endl;
		cout << "栈内无数据，退栈出错" << endl;
		system("pause");
		exit(0);
	}

}


//push() ,压栈函数
void Stack::Push(Localtion inStack)
{
	//先判断栈的空间大小，
	//空间足够插入一个新位置
	//不够就扩展10个步子空间，再插入
	if ( tag == size-1)
	{
		size += 20;
		stackSpace = (Localtion*)realloc(stackSpace, (size)*sizeof(Localtion));
		if (stackSpace == NULL)
		{
			cout << "realloc()  fail !" << endl;
		}
	}
	
	tag++;
	stackSpace[tag].x = inStack.x;
	stackSpace[tag].y = inStack.y;
//	cout << endl <<tag<< "push ( " << inStack.x << " , " << inStack.y << "  )" << "\t";

}

bool Stack::CheckLocaltionVaild(Localtion tempLocaltion)
{
	int i = 0;
	//if (tag == -1) return false;

	//0 给出发点
	for (i = 0; i <= tag; i++)
		if (tempLocaltion.x == stackSpace[i].x && tempLocaltion.y == stackSpace[i].y)
			break;

	if (i > tag)return true; //不在栈内，返回true，
	else return false;		//发现栈内有这点，返回false，
}

void Stack::ShowStack()
{
	int i = 0;
	cout << "Departure:   ";
	while (i <= tag)
	{
		cout << setw(4) << i << "(" << stackSpace[i].x << " , " << stackSpace[i].y << ")" << "--->";
		if (i % 5 == 0)//每行输出5个点
			cout << endl;
		i++;
	}
	cout << "Destination !";
}

Localtion Stack::GetTop()
{
	if (tag != -1)
		return stackSpace[tag];
	else
	{
		cout << "空栈栈底无元素" << endl;
		system("pause");
		exit(0);
	}
}

Stack::~Stack()
{
	free(stackSpace);
	tag = -1;
	size = 0;
}




