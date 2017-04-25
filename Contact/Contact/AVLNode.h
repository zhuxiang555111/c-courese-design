#pragma once
#include"info.h"


class AVLNode
{
public:
	info Data;
	int heigh; //高度
	AVLNode *left;
	AVLNode *right;

	//..............函数成员........................................//
	AVLNode()
		: left(NULL), right(NULL)
	{};//默认构造函数
	AVLNode(info data)    //显式值构造函数
		:Data(data), left(NULL), right(NULL)
	{};
	//................................................................//
};
//...............................节点类......................................// #pragma once

