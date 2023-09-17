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
  void updateStudent(Student *);
  void writeToTempFile(Student);
  void deleteStudent(Student *);
  bool isEmpty();
};

#endif // FILE_H
