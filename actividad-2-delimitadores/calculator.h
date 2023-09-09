#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define PIPE '|'
#define LINE_BREAK '\n'

class Calculator
{
private:
  int id;
  string operation;
  int num1;
  int num2;
  int res;
  string date;

public:
  Calculator();

  void sum();
  void subtraction();
  void multiplication();
  void division();

  void generateDate();

  int getId();
  void setId(int);
  string getOperation();
  void setOperation(string);
  int getNum1();
  void setNum1(int);
  int getNum2();
  void setNum2(int);
  string getDate();
  void setDate(string);
  int getRes();
  void setRes(int);

  friend ostream &operator<<(ostream &, const Calculator &);
  friend istream &operator>>(istream &, Calculator &);
};

#endif // CALCULATOR_H