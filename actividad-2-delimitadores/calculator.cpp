#include "calculator.h"

Calculator::Calculator()
{
}

void Calculator::sum()
{
  setRes(getNum1() + getNum2());
  setOperation("suma");
}

void Calculator::subtraction()
{
  setRes(getNum1() - getNum2());
  setOperation("resta");
}

void Calculator::multiplication()
{
  setRes(getNum1() * getNum2());
  setOperation("multiplicacion");
}

void Calculator::division()
{
  setRes(getNum1() / getNum2());
  setOperation("division");
}

int Calculator::getId()
{
  return id;
}

void Calculator::setId(int id)
{
  id = id;
}

string Calculator::getOperation()
{
  return operation;
}

void Calculator::setOperation(string op)
{
  operation = op;
}

int Calculator::getNum1()
{
  return num1;
}

void Calculator::setNum1(int n1)
{
  num1 = n1;
}

int Calculator::getNum2()
{
  return num2;
}

void Calculator::setNum2(int n2)
{
  num2 = n2;
}

int Calculator::getRes()
{
  return res;
}

void Calculator::setRes(int r)
{
  res = r;
}

string Calculator::getDate()
{
  return date;
}

void Calculator::setDate(string d)
{
  date = d;
}

ostream &operator<<(ostream &os, const Calculator &c)
{
  os << c.id << PIPE
     << c.operation << PIPE
     << c.num1 << PIPE
     << c.num2 << PIPE
     << c.res << PIPE
     << c.date << LINE_BREAK;

  return os;
}

istream &operator>>(istream &is, Calculator &c)
{
  string auxId, auxNum1, auxNum2, auxRes;

  getline(is, auxId, PIPE);
  getline(is, c.operation, PIPE);
  getline(is, auxNum1, PIPE);
  getline(is, auxNum2, PIPE);
  getline(is, auxRes, PIPE);
  getline(is, c.date, LINE_BREAK);

  c.id = atof(auxId.c_str());
  c.num1 = atof(auxNum1.c_str());
  c.num2 = atof(auxNum2.c_str());
  c.res = atof(auxRes.c_str());

  return is;
}