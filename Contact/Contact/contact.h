#pragma once
#include "person.h"
#include <list>
#include <fstream>


class contact
{
public:
	contact(string filename_para);
	void readFromFile();
	void writeToFile();
	friend void userInterface();

private:
	int TopMenu();
	int queryMenu();

	void insert_person();
	void insert_peraon(person p_insert);
	void update_person();
	bool delete_person(string name_para,string phone_para);
	void searchByName(string name_para);
	void searchByPhone(string phone_para);
	/*void searchByNamePhone(string name_para, string phone_para);*/
	void searchByAddress(string address_para);//fuzzy search
	void searchByRealation(string relation_para);
	void sortByName(ostream & out);
	

	list<person> contactBook;
	list<person>::iterator iter;
	void searchPriv(string name_para_priv, string phone_para_priv);
	person searchPrivFind;
	
	void printInfoFile(person p_pf);
	void printInfoScreen(person p_print);
	bool cmpName(person p1, person p2);
	
	//file module
	string filename;
};
