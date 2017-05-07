#include "contact.h"

contact::contact(string filename_para)
{
	filename = filename_para;
}

void contact::readFromFile()
{
	char buffer[256];
	char *cptr;
	person read_out;
	ifstream read_in(filename);
	if(!read_in.is_open())
		cout << "不能打开文件" << endl;
	else
	{
		while (read_in.getline(buffer, 256))
		{
			read_out.name = strtok_s(buffer, " ", &cptr);
			
		}
	}
}

void contact::insert_person(person p_insert)
{
	contactBook.push_back(p_insert);
}

void contact::update_person(string name_para, char * phone_para)
{
	;
	person update;
	for (iter = contactBook.begin(); iter != contactBook.end(); iter++)
	{
		if (name_para == (*iter).name)
		{
			if (phone_para == (*iter).phoneNumber)
			{
				*iter = update;
			}
			else
				cout << "用户名手机号不匹配!" << endl;
		}
		else
			cout << "不存在该用户！请检查用户名是否正确！" << endl;
	}
}

bool contact::delete_person(string name_para, char * phone_para)
{
	searchPrivFind.name = "";
	searchPriv(name_para, phone_para);
	if (searchPrivFind.name != "")
	{
		contactBook.remove(searchPrivFind);
		return true;
	}
	else
		return false; 
}

void contact::searchByName(string name_para)
{
	for (iter = contactBook.begin(); iter != contactBook.end(); iter++)
	{
		if ((*iter).name == name_para)
			printInfoScreen(*iter);
	}
}

void contact::searchByPhone(char * phone_para)
{
	for (iter = contactBook.begin(); iter != contactBook.end(); iter++)
	{
		if ((*iter).phoneNumber == phone_para)
			printInfoScreen(*iter);
	}
}

void contact::searchByAddress(string address_para)
{
	for (iter = contactBook.begin(); iter != contactBook.end(); iter++)
	{
		if (strstr(address_para.c_str(), (*iter).address.c_str()))
			printInfoScreen(*iter);
	}
}

void contact::searchByRealation(char * relation_para)
{
	for (iter = contactBook.begin(); iter != contactBook.end(); iter++)
	{
		if (relation_para == (*iter).relationType)
			printInfoScreen(*iter);
	}
}

void contact::sortByName(ostream & out)
{
	contactBook.sort(cmpName);
	for (iter = contactBook.begin(); iter != contactBook.end(); iter++)
	{
		printInfoScreen(*iter);
	}
}

void contact::searchPriv(string name_para_priv, char * phone_para_priv)
{
	for (iter = contactBook.begin(); iter != contactBook.end(); iter++)
	{
		if (name_para_priv == (*iter).name && phone_para_priv == (*iter).phoneNumber)
		{
				searchPrivFind = *iter;
		}
	}	
}

void contact::printInfoFile(person p_pf)
{
	cout << p_pf.name << " " << p_pf.sex << " " << p_pf.phoneNumber << " " << p_pf.address << " " << p_pf.postCode
		<< " " << p_pf.email << " " << p_pf.qqNumber << " " << p_pf.relationType << endl;
}

void contact::printInfoScreen(person p_print)
{
	cout << p_print.name << endl;
	cout << p_print.sex << endl;
	cout << p_print.phoneNumber << endl;
	cout << p_print.address << endl;
	cout << p_print.postCode << endl;
	cout << p_print.email << endl;
	cout << p_print.qqNumber << endl;
	cout << p_print.relationType << endl;
}

bool contact::cmpName(person p1, person p2)
{
	if (p1.name >= p2.name)
		return true;
}

void userInterface()
{
	//contact _c;

}
