#pragma once
#include "adminSystem.h"
#include<iostream>
#include<string>

using namespace std;


adminSystem::adminSystem()
{
}

adminSystem::~adminSystem()
{
}

void adminSystem::start()
{
	int createNew = 0;
	int modify_password;
	int user_choice;
	openFile("d:/adminSystem.txt");
	write_all_to_AVL();
	while (true)
	{
		cout << "1.用户登录(密码修改)    2.用户删除  " << endl << "输入序号确认:";
		cin >> user_choice;
		switch (user_choice)
		{
			//.................................1........................................//
		case 1:
			cout << "请输入用户id:";
			cin >> id;


			if (t1.search(id) != NULL)  //找到对应的用户 给出选项登录或者修改密码
			{
				information = t1.search_result(t1.search(id));
				cout << "登录后才能修改密码！！" << endl;
				if (login())
				{
					cout << "是否修改密码？1是，0否" << endl;
					cin >> modify_password;
					switch (modify_password)
					{
					case 0:goto next;
					case 1:
						update_information();
						goto next;//修改密码,登录成功后才能修改密码
					}
				}
			}
			else
			{
				cout << "用户不存在" << endl;
				cout << "是否创建新用户？1是，0否.........";
				cin >> createNew;
				switch (createNew)
				{
				case 0: goto next;
				case 1:create_new_user(); goto next;
				}
			}
			//.............................1......................................//


			//.............................2......................................//
		case 2:
			cout << "请输入id:";
			cin >> id;
			delete_user();
			//.................................2.....................................//
		}
	next:
		cout << "该轮程序结束！！" << endl;
	}
}

bool adminSystem::login()
{
	cout << "请输入用户ID:";
	cin >> id;
	string username;
	string userpassword;
	cout << endl << "请输入用户名:";
	cin >> username;
	cout << endl;
	cout << "请输入密码:";
	cin >> userpassword;
	while (userpassword != information.password)
	{
		cout << "用户名密码匹配失败,请重新输入" << endl;
		cout << "请输入密码:";
		cin >> userpassword;
	}
	cout << "用户名密码匹配成功!" << endl;
	return true;
}

void adminSystem::create_new_user()
{
	info new_information;
	int newindex;
	string newname, newpassword;
	cout << "请输入用户id:";
	cin >> newindex;
	cout << "请输入用户用户名:";
	cin >> newname;
	cout << "请输入用户密码:";
	cin >> newpassword;
	new_information.index = newindex;
	new_information.name = newname;
	new_information.password = newpassword;
	add(new_information);
}

void adminSystem::update_information()
{
	string updatepassword;
	cout << "请输入新密码:";
	cin >> updatepassword;
	information.password = updatepassword;
	delete_user();
	write_all_to_AVL();
	t1.insert(information);
	printInfo_toFile();
	write_all_to_AVL();
}

void adminSystem::delete_user()
{
	t1.remove(id);
	printInfo_toFile();
	write_all_to_AVL();
}
