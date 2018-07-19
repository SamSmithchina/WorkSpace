/******************************************************************
*
* Author：Sam Smith   wangbingzong@szkindom.com
* Time： 2018-05-25 16:20:05
* Version：V ...
* Description：
*
* Editor： sam 
* Time：	2018-06-05 09:13:07
* Modification：  已经上传到git hub
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

#include "Include.h"
#include "MazeGraph.h"
#include "Stack.h"

using namespace std;

enum  Direction{ Up, Down, Left, Right };	//0 = up ; 1 = down ,2 = left ,3 = right ;


int main()
{
	Stack myStack;
	MazeGraph myMaze;
	//Localtion Departure;
	//随机出发，目的地(1,0)；
	Localtion myLocaltion;
	Localtion tempLocaltion;
	Localtion nextLocaltion;
	int  i = 0, j = 0, k = 0;
	Direction  D;
	int count = 1;
	bool WhileTag = false;

	//十张随机地图走迷宫尝试
	//for (k = 0,count =1; k < 1; k++)
	//{
		D = Up;
		//myStack.InitStack();
		//开一张地图
		myMaze.CreateMaze();
		//产生一个随机地出发地点,范围在[0, x_axis-1] [0,y_yaxis-1]
		//范围 [x,y]; 公式 key = x + rand()%( y -x +1); 之前加 srand(time(0))
		//rand() 取值范围在 0 ` rand_max;
		do
		{
			srand(time(0));
			myLocaltion.x = 0 + rand() % (x_axis - 1 - 0 + 1);
			myLocaltion.y = 0 + rand() % (y_axis - 1 - 0 + 1);
		} while (!myMaze.CheckLoacltionVaild(myLocaltion));//不断产生地址，知道为true产生有效可行地址


		cout << endl << "Departure localtion is （ " << myLocaltion.x << " , " << myLocaltion.y << " )" << endl;
		cout << "Destination Localtion is ( 1 , 0 )" << endl;
		myMaze.DepartureInMaze(myLocaltion);	//标记出发点
		myMaze.DisplayMaze();	//展示地图
		nextLocaltion = myLocaltion;
		myStack.Push(nextLocaltion);

		//走迷宫规则
		//按上->下->左->右方向顺序寻路；
		//如果某个方向的下一点可以走，将下一点压栈，暂存到那一点
		//如果不行，换下一个方向尝试
		//如果四个方向都不行,退栈回到上一个地点，且不重走退栈的点方向和该方向之前的方向


		while (count++)
		{
			//上
			tempLocaltion.x = nextLocaltion.x;
			tempLocaltion.y = nextLocaltion.y + 1;
			if (tempLocaltion.y < y_axis && myMaze.CheckLoacltionVaild(tempLocaltion) && D == Up && myStack.CheckLocaltionVaild(tempLocaltion))
			{
				nextLocaltion = tempLocaltion;
				myStack.Push(nextLocaltion);
				D = Up;
			}
			else
			{

				//下
				if (D == Up)
					D = Down;
				tempLocaltion.x = nextLocaltion.x;
				tempLocaltion.y = nextLocaltion.y - 1;
				if (tempLocaltion.y >= 0 && myMaze.CheckLoacltionVaild(tempLocaltion) && D == Down && myStack.CheckLocaltionVaild(tempLocaltion))
				{
					nextLocaltion = tempLocaltion;
					myStack.Push(nextLocaltion);
					D = Up;
				}
				else
				{

					//左
					if (D == Down)
						D = Left;
					tempLocaltion.x = nextLocaltion.x - 1;
					tempLocaltion.y = nextLocaltion.y;
					if (tempLocaltion.x >= 0 && myMaze.CheckLoacltionVaild(tempLocaltion) && D == Left && myStack.CheckLocaltionVaild(tempLocaltion))
					{
						nextLocaltion = tempLocaltion;
						myStack.Push(nextLocaltion);
						D = Up;
					}
					else
					{

						//右
						if (D == Left)
							D = Right;
						tempLocaltion.x = nextLocaltion.x + 1;
						tempLocaltion.y = nextLocaltion.y;
						if (tempLocaltion.x < x_axis && myMaze.CheckLoacltionVaild(tempLocaltion) && D == Right && myStack.CheckLocaltionVaild(tempLocaltion))
						{
							nextLocaltion = tempLocaltion;
							myStack.Push(nextLocaltion);
							D = Up;
						}//end if 右
						else
						{
							//判断是否找到出路
							if (nextLocaltion.x == 1 && nextLocaltion.y == 0)
							{
								//myStack.Push(nextLocaltion);
								cout << "\n\n找到了一条路径 ：" << endl;
								myStack.ShowStack();
								break;
							}//if find the distinnation.

							//此时四个方向都走不通，方向为right,要退栈一次；
							//这里退栈需要小心处理退到空栈回到出发点的时候；极容易错误访问；
							//判断是否退回到起始点，此时四个方向都尝试后无法走通，则无路可走
							//if (nextLocaltion.x == myLocaltion.x && nextLocaltion.y == myLocaltion.y && D == Right)
							if (nextLocaltion.x == myLocaltion.x && nextLocaltion.y == myLocaltion.y)
							{
								cout << "\n have no way to go !" << endl<< "Find finish ! 寻路无果" << endl;
								break;
							}
							else
							{
								tempLocaltion = myStack.Pop();
								nextLocaltion = myStack.GetTop();

								//右侧退回的则一直退栈；因为右侧没有路就表明当前这点没有可行性
								while (tempLocaltion.x > nextLocaltion.x)
								{
									tempLocaltion = myStack.Pop();
									nextLocaltion = myStack.GetTop();
									if (nextLocaltion.x == myLocaltion.x && nextLocaltion.y == myLocaltion.y)
									{
										cout << "\n have no way to go !" << endl << "右侧回退到出发点 !" << endl;
										WhileTag = true;
										break;
									}
								}
								//两次上面循环结束，whiletag为 true ,表明右侧回溯到出发点，无路可走，会退出寻路
								if (WhileTag)
									break;
								//旧的方向和该方向之前的方向不在走
								if (tempLocaltion.y > nextLocaltion.y)
								{//从上方退栈回退到下方，不重走当前的上方
									D = Down;
								}
								if (tempLocaltion.y < nextLocaltion.y)
								{
									//下方退栈回到上方，不重走上下方向
									D = Left;
								}
								if (tempLocaltion.x < nextLocaltion.x)
								{
									//从左侧退栈回到右侧，不重走上下左侧
									D = Right;
								}
							}
						}
					}//else 四个方向不行就退栈
				}//else 左
			}//else 下
		}//while while --> if  上
		
		cout << "\n\n\n***													***" << endl;
		cout << "***													***" << endl;
		cout << "***\t\t第 " << k << "张迷宫寻路完成 \t\t\t\t\t\t\t\t\t***" << endl;
		cout << "***													***" << endl;
		cout << "***													***" << endl;
		cout << "\n\n*********************************************************\n\n" << endl;
		system("pause");

//	}//for 运行10张地图;

	myStack.~Stack();
	return 0;
}
