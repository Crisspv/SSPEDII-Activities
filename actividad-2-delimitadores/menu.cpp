#include "menu.h"

Menu::Menu()
{
}

void Menu::cls()
{
#ifdef WINDOWS
  system("cls");
#else
  system("clear");
#endif
}

void Menu::enterToContinue()
{
  cout << "\nPresione <enter> para continuar..." << endl;
  getchar();
}

void Menu::showMainMenu()
{
  char choice;

  do
  {
    cls();
    cout << "1. Calculadora" << endl;
    cout << "2. Archivo" << endl;
    cout << "c. Salir" << endl
         << endl;

    cout << "Opcion: ";
    cin >> choice;
    cin.ignore();

    switch (choice)
    {
    case '1':
      calculatorMenu();
      break;

    case '2':
      break;

    case 'c':
      break;
    default:
      cout << "opcion incorrecta..." << endl;
      enterToContinue();
    }
  } while (choice != 'c');
}

void Menu::calculatorMenu()
{
  char choice;
  Calculator myCalc;
  File myFile;

  do
  {
    cls();
    cout << "MENU CALCULADORA" << endl
         << endl;
    cout << "1. Suma" << endl;
    cout << "2. Resta" << endl;
    cout << "3. Multiplicacion" << endl;
    cout << "4. Division" << endl;
    cout << "c. Regresar" << endl
         << endl;

    cout << "Opcion: ";
    cin >> choice;
    cin.ignore();

    switch (choice)
    {
    case '1':
      int num1, num2;

      cout << "Ingresa num1: ";
      cin >> num1;
      cin.ignore();

      cout << "Ingresa num2: ";
      cin >> num2;
      cin.ignore();

      myCalc.setNum1(num1);
      myCalc.setNum2(num2);
      myCalc.sum();

      cout << "El resultado de la suma es: " << myCalc.getRes() << endl;
      myFile.writeToFile();
      enterToContinue();

      break;

    case '2':
      break;

    case '3':
      break;

    case '4':
      break;

    case 'c':
      break;
    default:
      cout << "opcion incorrecta..." << endl;
      enterToContinue();
    }
  } while (choice != 'c');
}