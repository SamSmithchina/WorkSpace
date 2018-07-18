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


#ifndef MAZEGRAPH_H
#define MAZEGRAPH_H
#include "Stack.h"

#define x_axis 10
#define y_axis 10

//以图的左下角为坐标轴零点
//x轴范围0-x_axis
//y轴范围0-y_axis
//(x,y)点L在图中表示为MazeSpace[L.column][L.row]

class MazeGraph : public Localtion
{
private:
	int MazeSpace[x_axis][y_axis];
public:
	//MazeGraph();
	void CreateMaze();
	void DepartureInMaze(Localtion L);	//出发点999、终点设置为1000，
	bool CheckLoacltionVaild(Localtion L);//判断点可行
	void DisplayMaze();
	//~MazeGraph();

};




#endif