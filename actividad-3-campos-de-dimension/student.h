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
  float generalAverage;

public:
  Student();

  int getCode();
  void setCode(int);
  string getName();
  void setName(string);
  string getLastName();
  void setLastName(string);
  int getSemester();
  void setSemester(int);
  float getGeneralAverage();
  void setGeneralAverage(float);

  friend ostream &operator<<(ostream &, const Student &);
  friend istream &operator>>(istream &, Student &);
};

#endif // STUDENT_H