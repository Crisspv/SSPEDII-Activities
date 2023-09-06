#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
using namespace std;

class Calculator
{
    public:
        Calculator();
        ~Calculator();
        int sum(int,int);
        int sub(int,int);
        int mult(int,int);
        int div(int,int);

        int getNum1();
        void setNum1(int);
        int getNum2();
        void setNum2(int);
        int getRes();
        void setRes(int);
        string getOperation();
        void setOperation(string);

    private:
        int n1;
        int n2;
        int res;
        string operation;
};

#endif // CALCULATOR_H
