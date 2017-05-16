#pragma once
#include<iostream>
#include <fstream>
#include "person.h"
using namespace std;

class fileReader
{
public:
	fileReader(string filename);
	void openFile(string filename);

private:
	person p;
};