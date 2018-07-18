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


#include"MazeGraph.h"
#include<time.h>
#include<stdlib.h>
using namespace std;

void MazeGraph::CreateMaze()
{

	int i, j;
	int sum=0;
	int temp=0;
	//0表示无障碍；1表示障碍
	//迷宫边界0
	for (i = 0; i < x_axis; i++)
	{
		MazeSpace[i][0] = 1;
		MazeSpace[i][y_axis - 1] = 1;
	}
	for (j = 0; j < y_axis; j++)
	{
		MazeSpace[0][j] = 1;
		MazeSpace[x_axis - 1][j] = 1;
	}

	//rand()产生迷宫障碍；
	for (i = 1; i < x_axis - 1; i++)
		for (j = 1; j < y_axis - 1; j++)
		{
			//	srand(time(0));
			//    temp = 0 + rand() % (9-0+1);
			temp = rand() % 100;
			if (temp < 70)
				MazeSpace[i][j] = 0;
			else
				MazeSpace[i][j] = 1;
		}
	//为避免某一行全为1；需要校验一次；
	for (i = 0; i < x_axis; i++)
	{
		for (j = 0; j < y_axis; j++)
		{
			sum += MazeSpace[i][j];
		}
		
		if (sum == x_axis)//一行全为1；
		{
			temp = rand() % x_axis;
			if (temp < x_axis*0.7)
			{
				MazeSpace[i][temp] = 0;
				MazeSpace[i][(temp + 2) % x_axis] = 0;
				MazeSpace[i][(temp + 4) % x_axis] = 0;
				MazeSpace[i][(temp + 5) % x_axis] = 0;
				MazeSpace[i][(temp + 6) % x_axis] = 0;
				MazeSpace[i][(temp + 7) % x_axis] = 0;
			}//if
		}//if
		sum = 0;
	}
	MazeSpace[1][0] = 1000;//destinnation

}

void MazeGraph::DisplayMaze()
{
	cout << "Here is a Maze Map" << endl;

	for (int j = x_axis -1; j >= 0; j--)
	{

		cout << setw(5) << j << ":\t";
		for (int i = 0; i < x_axis; i++)
		{
			cout << setw(5) << MazeSpace[i][j];
		}

		cout << endl;
	}
	cout << endl << "\t";
	for ( int i = 0; i < x_axis; i++)
		cout << setw(5) << i ;
}

////出发点清零，
void MazeGraph::DepartureInMaze(Localtion L)
{
	MazeSpace[L.x][L.y] = 999;

}

//判断点可行
bool MazeGraph::CheckLoacltionVaild(Localtion L)
{
	if (MazeSpace[L.x][L.y]==0 || MazeSpace[L.x][L.y] == 1000) //从终点值为1000 和 0值点走判为有效路径
		return true;
	else return false;
}
