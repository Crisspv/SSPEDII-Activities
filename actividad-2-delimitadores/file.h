#ifndef FILE_H
#define FILE_H

#include <fstream>
#include <list>
#include "calculator.h"

#define FILE_NAME "calculator_registry.txt"
#define TEMP_FILE_NAME "temp.txt"

using namespace std;

class File
{
private:
public:
  File();

  list<Calculator> readFromFile();
  void writeToFile(Calculator);
  void writeListToTempFile(list<Calculator>);

  int getLastId();
};

#endif // FILE_H