#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <algorithm>

#include "calculator.h"
#include "file.h"

using namespace std;

class Menu
{
private:
  void cls();
  void enterToContinue();
  void calculatorMenu();
  void fileMenu();
  void printCalc(Calculator);
  void modifyCalc(Calculator &);

public:
  Menu();

  void showMainMenu();
};

#endif // MENU_H