#pragma once
#include<iostream>
using namespace std;
class info
{
public:
	info()
		:index(0), name(" "), password(" ")
	{};
	info(int i, string n, string p)
		:index(i), name(n), password(p)
	{};
	int index; //Ë÷Òý
	string name;
	string password;
};

