#ifndef MENU_H
#define MENU_H

#include <iostream>

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
  void modifyRegistry(Calculator &);

public:
  Menu();

  void showMainMenu();
};

#endif // MENU_H