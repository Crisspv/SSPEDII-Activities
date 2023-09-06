#include "Calculator.h"

Calculator::Calculator()
{

}

Calculator::~Calculator()
{
    // lmipiar RAM
}

int Calculator::sum(int n1, int n2)
{
    int result = getNum1() + getNum2();
    setRes(result);
}

int Calculator::sub(int, int)
{
    int result = getNum1() - getNum2();
    setRes(result);
}

int Calculator::mult(int, int)
{
    int result = getNum1() * getNum2();
    setRes(result);
}

int Calculator::div(int, int)
{
    int result = getNum1() / getNum2();
    setRes(result);
}

int Calculator::getNum1()
{
   return n1;
}

void Calculator::setNum1(int num1)
{
    n1 = num1;
}

int Calculator::getNum2()
{
    return n2;
}

void Calculator::setNum2(int num2)
{
    n2 = num2;
}

int Calculator::getRes()
{
    return res;
}

void Calculator::setRes(int result)
{
    res = result;
}

string Calculator::getOperation()
{
    return operation;
}

void Calculator::setOperation(string op)
{
    operation = op;
}
