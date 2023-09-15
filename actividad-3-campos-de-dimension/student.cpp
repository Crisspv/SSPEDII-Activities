#include "student.h"

Student::Student()
{
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

float Student::getGeneralAverage()
{
  return generalAverage;
}

void Student::setGeneralAverage(float gA)
{
  generalAverage = gA;
}

ostream &operator<<(ostream &os, const Student &s)
{
  os << sizeof s.code
     << s.code
     << sizeof s.name
     << s.name
     << sizeof s.lastName
     << s.lastName
     << sizeof s.semester
     << s.semester
     << sizeof s.generalAverage
     << s.generalAverage;

  return os;
}

istream &operator>>(istream &is, Student &s)
{
}