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
		cout << "1.�û���¼(�����޸�)    2.�û�ɾ��  " << endl << "�������ȷ��:";
		cin >> user_choice;
		switch (user_choice)
		{
			//.................................1........................................//
		case 1:
			cout << "�������û�id:";
			cin >> id;


			if (t1.search(id) != NULL)  //�ҵ���Ӧ���û� ����ѡ���¼�����޸�����
			{
				information = t1.search_result(t1.search(id));
				cout << "��¼������޸����룡��" << endl;
				if (login())
				{
					cout << "�Ƿ��޸����룿1�ǣ�0��" << endl;
					cin >> modify_password;
					switch (modify_password)
					{
					case 0:goto next;
					case 1:
						update_information();
						goto next;//�޸�����,��¼�ɹ�������޸�����
					}
				}
			}
			else
			{
				cout << "�û�������" << endl;
				cout << "�Ƿ񴴽����û���1�ǣ�0��.........";
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
			cout << "������id:";
			cin >> id;
			delete_user();
			//.................................2.....................................//
		}
	next:
		cout << "���ֳ����������" << endl;
	}
}

bool adminSystem::login()
{
	cout << "�������û�ID:";
	cin >> id;
	string username;
	string userpassword;
	cout << endl << "�������û���:";
	cin >> username;
	cout << endl;
	cout << "����������:";
	cin >> userpassword;
	while (userpassword != information.password)
	{
		cout << "�û�������ƥ��ʧ��,����������" << endl;
		cout << "����������:";
		cin >> userpassword;
	}
	cout << "�û�������ƥ��ɹ�!" << endl;
	return true;
}

void adminSystem::create_new_user()
{
	info new_information;
	int newindex;
	string newname, newpassword;
	cout << "�������û�id:";
	cin >> newindex;
	cout << "�������û��û���:";
	cin >> newname;
	cout << "�������û�����:";
	cin >> newpassword;
	new_information.index = newindex;
	new_information.name = newname;
	new_information.password = newpassword;
	add(new_information);
}

void adminSystem::update_information()
{
	string updatepassword;
	cout << "������������:";
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
