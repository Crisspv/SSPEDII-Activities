#include "student.h"

Student::Student()
{
}

Student::Student(int code, string name, string lastName, int semester, int generalAverage)
{
  this->code = code;
  this->name = name;
  this->lastName = lastName;
  this->semester = semester;
  this->generalAverage = generalAverage;
}

int Student::getCode()
{
  return code;
}

void Student::setCode(int c)
{
  code = c;
}

string Student::getName()
{
  return name;
}

void Student::setName(string n)
{
  name = n;
}

string Student::getLastName()
{
  return lastName;
}

void Student::setLastName(string lN)
{
  lastName = lN;
}

int Student::getSemester()
{
  return semester;
}

void Student::setSemester(int s)
{
  semester = s;
}

int Student::getGeneralAverage()
{
  return generalAverage;
}

void Student::setGeneralAverage(int gA)
{
  generalAverage = gA;
}