#ifndef FILE_H
#define FILE_H

#include <fstream>
#include <list>
#include "student.h"
#include <sstream>

using namespace std;

#define FILE_NAME "students.txt"
#define TEMP_FILE_NAME "temp.txt"
#define EMPTY '\0'

class File
{
private:
public:
  File();

  void writeToFile(Student);
  list<Student> loadAllStudents();
  Student *findStudent(int);
};

#endif // FILE_H
