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
			read_out.sex = strtok_s(buffer, " ", &cptr);
			read_out.phoneNumber = strtok_s(buffer, " ", &cptr);
			read_out.address = strtok_s(buffer, " ", &cptr);
			read_out.postCode = strtok_s(buffer, " ", &cptr);
			read_out.email = strtok_s(buffer, " ", &cptr);
			read_out.qqNumber = strtok_s(buffer, " ", &cptr);
			read_out.relationType = strtok_s(buffer, " ", &cptr);
			insert_person(read_out);
		}
	}
	

}

void contact::writeToFile()
{
	for (iter = contactBook.begin(); iter != contactBook.end(); iter++)
	{
		printInfoFile(*iter);
	}
}

int contact::TopMenu()
{
	int choice;
	cout << "[1] query person" << endl;
	cout << "[2] insert new person" << endl;
	cout << "[3] Sort out the person's information according to the name" << endl;
	cout << "[4] upadate person by name and phone" << endl;
	cout << "[5] delete person by name and phone" << endl;
	cin >> choice;
	return choice;
}

int contact::queryMenu()
{
	int choice;
	cout << "[1] query person by name and phone" << endl;
	cout << "[2] query person by address" << endl;
	cout << "[3] query person by relation tyepe" << endl;
	return choice;
}

void contact::insert_person()
{
	person p_insert;
	string name_in, sex_in, phoneNumber_in, address_in, postCode_in, email_in, qqNumber_in, relationType_in;
	cout << "input new person name:";
	cin >> name_in;
	p_insert.name = name_in;
	cout << "input new person sex:";
	cin >> sex_in;
	cout << "input new person phone:";
	p_insert.sex = sex_in;
	cin >> phoneNumber_in;
	p_insert.phoneNumber = phoneNumber_in;
	cout << "input new address:";
	cin >> address_in;
	p_insert.address = address_in;
	cout << "input new person postcode:";
	cin >> postCode_in;
	p_insert.postCode = postCode_in;
	cout << "input new person email:";
	cin >> email_in;
	p_insert.email = email_in;
	cout << "input new person qq number:";
	cin >> qqNumber_in;
	p_insert.qqNumber = qqNumber_in;
	cout << "input new person relation type";
	cin >> relationType_in;
	p_insert.relationType = relationType_in;
	contactBook.push_back(p_insert);
}

void contact::insert_peraon(person p_insert)
{
	contactBook.push_back(p_insert);
}

void contact::update_person()
{
	string name_in, phone_in;
	cout << "input person updated name:";
	cin >> name_in;
	cout << "input person updated phone";
	cin >> phone_in;
	for (iter = contactBook.begin(); iter != contactBook.end(); iter++)
	{
		if (name_in == (*iter).name)
		{
			if (phone_in == (*iter).phoneNumber)
			{
				person update;
				string sex_in, address_in, postcode_in, email_in, qqnumber_in, relation_in;
				update.name = name_in;
				update.phoneNumber = phone_in;
				cout << "input new person name:";
				cout << "input new person sex:";
				cin >> sex_in;
				cout << "input new person phone:";
				update.sex = sex_in;
				cout << "input new address:";
				cin >> address_in;
				update.address = address_in;
				cout << "input new person postcode:";
				cin >> postcode_in;
				update.postCode = postcode_in;
				cout << "input new person email:";
				cin >> email_in;
				update.email = email_in;
				cout << "input new person qq number:";
				cin >> qqnumber_in;
				update.qqNumber = qqnumber_in;
				cout << "input new person relation type";
				cin >> relation_in;
				update.relationType = relation_in;
				*iter = update;
			}
			else
				cout << "用户名手机号不匹配!" << endl;
		}
		else
			cout << "不存在该用户！请检查用户名是否正确！" << endl;
	}
}

bool contact::delete_person(string name_para, string  phone_para)
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

void contact::searchByPhone(string phone_para)
{
	for (iter = contactBook.begin(); iter != contactBook.end(); iter++)
	{
		if ((*iter).phoneNumber == phone_para)
			printInfoScreen(*iter);
	}
}

//void contact::searchByNamePhone(string name_para, string phone_para)
//{
//	for (iter = contactBook.begin(); iter != contactBook.end(); iter++)
//	{
//		if (name_para == (*iter).name)
//		{
//			if (phone_para == (*iter).phoneNumber)
//			{
//				cout
//			}
//			else
//				cout << "用户名手机号不匹配!" << endl;
//		}
//		else
//			cout << "不存在该用户！请检查用户名是否正确！" << endl;
//	}
//}

void contact::searchByAddress(string address_para)
{
	for (iter = contactBook.begin(); iter != contactBook.end(); iter++)
	{
		if (strstr(address_para.c_str(), (*iter).address.c_str()))
			printInfoScreen(*iter);
	}
}

void contact::searchByRealation(string relation_para)
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

void contact::searchPriv(string name_para_priv, string phone_para_priv)
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
	ofstream tofile;
	tofile << p_pf.name << " " << p_pf.sex << " " << p_pf.phoneNumber << " " << p_pf.address << " " << p_pf.postCode
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

void startProgram()
{

}

void userInterface()
{
	contact _c("c:/contact.txt");
	_c.readFromFile();
	while (true)
	{
		int choice1 = _c.TopMenu();
		switch (choice1)//top menu
		{
			case(1):
			{
				int choice2 = _c.queryMenu();
				switch (choice2)//query menu
				{
					case(1):
					{
						string name_in, phone_in;
						cout << "input name:";
						cin >> name_in;
						cout << "input phone number:";
						cin >> phone_in;
						_c.searchPriv(name_in, phone_in);
						_c.printInfoScreen(_c.searchPrivFind);
						break;
					}
					case(2):
					{
						string address_in;
						cout << "input address:";
						cin >> address_in;
						_c.searchByAddress(address_in);
						break;
					}
					case(3):
					{
						string type_in;
						cout << "input relation type:";
						cin >> type_in;
						_c.searchByRealation(type_in);
						break;
					}
				}

			}
			case(2):
			{
				_c.insert_person();
			}
			case(3):
			{
				_c.sortByName(cout);
			}
			case(4):
			{
				_c.update_person();
			}
			case(5):
			{

			}
		}
	}

}
