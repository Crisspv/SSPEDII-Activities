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
    // cls();
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
      fileMenu();
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
  int num1, num2, newId;

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
      cout << "Ingresa num1: ";
      cin >> num1;
      cin.ignore();

      cout << "Ingresa num2: ";
      cin >> num2;
      cin.ignore();

      // obtener id
      newId = myFile.getLastId() + 1;
      myCalc.setId(newId);
      myCalc.setNum1(num1);
      myCalc.setNum2(num2);
      myCalc.sum();

      cout << "El resultado de la suma es: " << myCalc.getRes() << endl;
      myFile.writeToFile(myCalc);
      enterToContinue();

      break;

    case '2':
      cout << "Ingresa num1: ";
      cin >> num1;
      cin.ignore();

      cout << "Ingresa num2: ";
      cin >> num2;
      cin.ignore();

      myCalc.setNum1(num1);
      myCalc.setNum2(num2);
      myCalc.subtraction();

      cout << "El resultado de la resta es: " << myCalc.getRes() << endl;
      myFile.writeToFile(myCalc);
      enterToContinue();
      break;

    case '3':
      cout << "Ingresa num1: ";
      cin >> num1;
      cin.ignore();

      cout << "Ingresa num2: ";
      cin >> num2;
      cin.ignore();

      myCalc.setNum1(num1);
      myCalc.setNum2(num2);
      myCalc.multiplication();

      cout << "El resultado de la multiplicacion es: " << myCalc.getRes() << endl;
      myFile.writeToFile(myCalc);
      enterToContinue();
      break;

    case '4':
      cout << "Ingresa num1: ";
      cin >> num1;
      cin.ignore();

      cout << "Ingresa num2: ";
      cin >> num2;
      cin.ignore();

      myCalc.setNum1(num1);
      myCalc.setNum2(num2);
      myCalc.division();

      cout << "El resultado de la division es: " << myCalc.getRes() << endl;
      myFile.writeToFile(myCalc);
      enterToContinue();
      break;

    case 'c':
      break;
    default:
      cout << "opcion incorrecta..." << endl;
      enterToContinue();
    }
  } while (choice != 'c');
}

void Menu::fileMenu()
{
  char choice;

  File myFile;
  list<Calculator> calcList;
  list<Calculator>::iterator it;

  do
  {
    cls();
    cout << "MENU ARCHIVO" << endl
         << endl;

    cout << "1. Agregar" << endl;
    cout << "2. Mostrar todo" << endl;
    cout << "c. Regresar"
         << endl
         << endl;

    cout << "Opcion: ";
    cin >> choice;
    cin.ignore();

    switch (choice)
    {
    case '1':

      break;

    case '2':
      calcList = myFile.readFromFile();
      for (it = calcList.begin(); it != calcList.end(); ++it)
      {
        printCalc(*it);
      }
      enterToContinue();
      break;

    case 'c':
      break;

    default:
      cout << "opcion incorrecta..." << endl;
      enterToContinue();
    }
  } while (choice != 'c');
}

void Menu::printCalc(Calculator calc)
{
  cout << "Id:        " << calc.getId() << endl;
  cout << "Operacion: " << calc.getOperation() << endl;
  cout << "Num1:      " << calc.getNum1() << endl;
  cout << "Num2:      " << calc.getNum2() << endl;
  cout << "Res:       " << calc.getRes() << endl;
  cout << "Fecha:     " << calc.getDate() << endl
       << endl;
}