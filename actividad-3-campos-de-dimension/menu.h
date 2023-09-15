#ifndef MENU_H
#define MENU_H

#include <iostream>
using namespace std;

#include "student.h"
#include "file.h"

class Menu
{
private:
  void cls();
  void enterToContinue();
  void printStudent(Student);
  void modifyStudent(Student &);

public:
  Menu();

  void mainMenu();
};

#endif // MENU_H
