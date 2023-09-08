#ifndef FILE_H
#define FILE_H

#include <fstream>
#include <list>
#include "calculator.h"

#define FILE_NAME "calculator_registry.txt"

using namespace std;

class File
{
private:
  list<Calculator> *calculatorList;

public:
  File();

  void readFromFile();
  void writeToFile();

  void addToList(Calculator);
};

#endif // FILE_H