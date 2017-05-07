#pragma once
#include "person.h"
#include <list>
#include <fstream>


class contact
{
public:
	contact(string filename_para);
	void readFromFile();

	void insert_person(person p_insert);
	void update_person(string name_para, char *phone_para);
	bool delete_person(string name_para,char *phone_para);
	void searchByName(string name_para);
	void searchByPhone(char *phone_para);
	void searchByAddress(string address_para);//fuzzy search
	void searchByRealation(char * relation_para);
	void sortByName(ostream & out);
	friend void userInterface();
private:
	list<person> contactBook;
	list<person>::iterator iter;
	void searchPriv(string name_para_priv, char *phone_para_priv);
	person searchPrivFind;
	
	void printInfoFile(person p_pf);
	void printInfoScreen(person p_print);
	bool cmpName(person p1, person p2);
	
	//file module
	string filename;
};
