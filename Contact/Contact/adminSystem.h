#pragma once
#include<iostream>
#include"AVLTree.h"
#include"fileReader.h"

class adminSystem : public fileReader
{
public:
	adminSystem();
	~adminSystem();
	void start();
	bool login();
	void create_new_user();
	void update_information();
	void delete_user();

private:
	//fileReader FR1;
	int id;  //��ǰ�û�id
	info information;  //��ǰ�û���Ϣ
};