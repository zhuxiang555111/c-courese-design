#pragma once
#include"info.h"


class AVLNode
{
public:
	info Data;
	int heigh; //�߶�
	AVLNode *left;
	AVLNode *right;

	//..............������Ա........................................//
	AVLNode()
		: left(NULL), right(NULL)
	{};//Ĭ�Ϲ��캯��
	AVLNode(info data)    //��ʽֵ���캯��
		:Data(data), left(NULL), right(NULL)
	{};
	//................................................................//
};
//...............................�ڵ���......................................// #pragma once

