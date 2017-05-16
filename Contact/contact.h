#pragma once
#include "person.h"
#include <list>
#include <fstream>
#include <algorithm>

class contact
{
public:
	contact(string filename_para);
	void readFromFile();
	void writeToFile();
	friend int main();

private:
	int TopMenu();
	int queryMenu();

	void insert_person();
	void insert_person(person p_insert);
	void update_person();
	void delete_person();
	void searchByName(string name_para);
	void searchByPhone(string phone_para);
	/*void searchByNamePhone(string name_para, string phone_para);*/
	void searchByAddress(string address_para);//fuzzy search
	void searchByRealation(string relation_para);
	void sortByName();
	

	list<person> contactBook;
	list<person>::iterator iter;
	void searchPriv(string name_para_priv, string phone_para_priv);
	person searchPrivFind;
	
	void printInfoFile(person p_pf);
	void printInfoScreen(person p_print);
	bool cmpName(const person& p1,const person& p2);
	
	//file module
	string filename;
};
