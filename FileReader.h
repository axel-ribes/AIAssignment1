#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "Graph.h"

class FileReader
{
private :
	std::string fileName;

public:
	FileReader(std::string fileName);
	Graph readFile();
}; //FileReader

