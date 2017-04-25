#pragma once
#include "fileReader.h"


fileReader::fileReader()
{
}

fileReader::fileReader(string filename)
{
	m_filename = filename;
}

fileReader::~fileReader()
{
}

void fileReader::openFile(string filename)
{
	m_filename = filename;
}

void fileReader::write_all_to_AVL()
{
	char buffer[256];
	char *p;
	string strindex, strname, strpassword;//指向strtok切割出来的字符串
	ifstream read_from_file(m_filename);
	if (!read_from_file.is_open())
		cout << "不能打开文件" << endl;
	else
	{
		while (read_from_file.getline(buffer, 100))
		{
			strindex = strtok_s(buffer, " ", &p); //strtok分割字符串  
			strname = strtok_s(NULL, " ", &p);
			strpassword = strtok_s(NULL, "\n", &p);
			info tempInfo(atoi(strindex.c_str()), strname, strpassword);
			t1.insert(tempInfo);
		}
	}

}

void fileReader::delete_piece(int index)
{
	t1.remove(index);
}

void fileReader::printfindex()
{
	t1.graph(cout);
}

void fileReader::printInfo()
{
	t1.inorder(cout);
}

void fileReader::printInfo_toFile()
{
	ofstream write_to_file(m_filename);
	t1.inorder(write_to_file);
}

void fileReader::add(info newInfo)
{
	t1.insert(newInfo);
	printInfo_toFile();
}

