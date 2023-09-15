#ifndef FILE_H
#define FILE_H

#include <fstream>
#include <list>
#include "student.h"
using namespace std;

#define FILE_NAME "students.txt"
#define TEMP_FILE_NAME "temp.txt"

class File
{
private:
public:
  File();

  list<Student> readFromFile();
  void writeToFile(Student);
  void writeListToTempFile(list<Student>);

  bool isCodeExisting(int);
};

#endif // FILE_H
