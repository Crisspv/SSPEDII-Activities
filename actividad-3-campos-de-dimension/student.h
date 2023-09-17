#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
using namespace std;

class Student
{
private:
  int code;
  string name;
  string lastName;
  int semester;
  int generalAverage;

public:
  Student();
  Student(int, string, string, int, int);

  int getCode();
  void setCode(int);
  string getName();
  void setName(string);
  string getLastName();
  void setLastName(string);
  int getSemester();
  void setSemester(int);
  int getGeneralAverage();
  void setGeneralAverage(int);
};

#endif // STUDENT_H