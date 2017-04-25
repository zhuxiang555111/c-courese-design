#pragma once
#include<iostream>
#include<fstream>
#include"AVLTree.h"
#include<string>

//读取txt文件中每一行，并将信息写入AVL树中
class fileReader
{
public:
	fileReader();
	fileReader(string filename);
	~fileReader();
	void openFile(string filename);
	void write_all_to_AVL();
	void delete_piece(int index);
	void printfindex();
	void printInfo();
	void printInfo_toFile();
	void add(info newInfo);
protected:
	string m_filename;
	AVLTree t1;
};

