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
public:
  File();

  list<Calculator> readFromFile();
  void writeToFile(Calculator);
  int getLastId();
};

#endif // FILE_H