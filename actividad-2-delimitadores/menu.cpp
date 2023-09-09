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
    cout << "MENU PRINCIPAL" << endl
         << endl;
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

      newId = myFile.getLastId() + 1;
      myCalc.setId(newId);
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

      newId = myFile.getLastId() + 1;
      myCalc.setId(newId);
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

      newId = myFile.getLastId() + 1;
      myCalc.setId(newId);
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
  Calculator myCalc;
  list<Calculator> calcList;
  list<Calculator>::iterator it;

  int search;
  char operation;
  bool isFound = false;

  do
  {
    cls();
    cout << "MENU ARCHIVO" << endl
         << endl;

    cout << "1. Agregar" << endl;
    cout << "2. Mostrar todo" << endl;
    cout << "3. Buscar" << endl;
    cout << "4. Modificar" << endl;
    cout << "5. eliminar" << endl;
    cout << "c. Regresar"
         << endl
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
      calcList = myFile.readFromFile();
      for (it = calcList.begin(); it != calcList.end(); ++it)
      {
        printCalc(*it);
      }
      enterToContinue();
      break;

    case '3':
      int search;
      cout << "Ingresa el id a buscar: ";
      cin >> search;
      cin.ignore();

      calcList = myFile.readFromFile();
      for (it = calcList.begin(); it != calcList.end(); ++it)
      {
        if (search == it->getId())
        {
          isFound = true;
          printCalc(*it);
          enterToContinue();
          break;
        }
      }

      if (!isFound)
      {
        cout << "Registro no encontrado..." << endl;
        enterToContinue();
      }
      break;

    case '4':
      cout << "Ingresa el id a modificar: ";
      cin >> search;
      cin.ignore();

      calcList = myFile.readFromFile();
      for (it = calcList.begin(); it != calcList.end(); ++it)
      {
        if (search == it->getId())
        {
          isFound = true;
          modifyRegistry(*it);
          break;
        }
      }

      if (!isFound)
      {
        cout << "Reistro no encontrado..." << endl;
        enterToContinue();
      }

      myFile.writeListToTempFile(calcList);
      myFile.renameFiles();
      cout << "Registro modificado con exito..." << endl;
      enterToContinue();
      break;

    case '5':
      cout << "Ingresa el id a elminar: ";
      cin >> search;
      cin.ignore();

      calcList = myFile.readFromFile();
      it = calcList.begin();
      while (it != calcList.end())
      {
        if (search == it->getId())
        {
          isFound = true;
          cout << "Registro encontrado!" << endl;
          printCalc(*it);
          it = calcList.erase(it);
          break;
        }
        else
        {
          it++;
        }
      }

      if (!isFound)
      {
        cout << "Registro no encontrado..." << endl;
        enterToContinue();
      }
      else
      {
        myFile.writeListToTempFile(calcList);
        myFile.renameFiles();
        cout << "Registro eliminado con exito..." << endl;
        enterToContinue();
      }
      break;

    case 'c':
      break;

    default:
      cout << "opcion incorrecta..." << endl;
      enterToContinue();
    }
  } while (choice != 'c');
}

void Menu::modifyRegistry(Calculator &calc)
{
  char choice;
  int num1, num2;

  do
  {
    cls();
    cout << "Elemento encontrado!" << endl
         << endl;

    printCalc(calc);

    cout << "Elije operacion nueva:" << endl;
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
      cout << "Num1: ";
      cin >> num1;
      cin.ignore();

      cout << "Num2: ";
      cin >> num2;
      cin.ignore();

      calc.setNum1(num1);
      calc.setNum2(num2);
      calc.sum();
      choice = 'c';
      break;

    case '2':
      cout << "Num1: ";
      cin >> num1;
      cin.ignore();

      cout << "Num2: ";
      cin >> num2;
      cin.ignore();

      calc.setNum1(num1);
      calc.setNum2(num2);
      calc.subtraction();
      choice = 'c';
      break;

    case '3':
      cout << "Num1: ";
      cin >> num1;
      cin.ignore();

      cout << "Num2: ";
      cin >> num2;
      cin.ignore();

      calc.setNum1(num1);
      calc.setNum2(num2);
      calc.multiplication();
      choice = 'c';
      break;

    case '4':
      cout << "Num1: ";
      cin >> num1;
      cin.ignore();

      cout << "Num2: ";
      cin >> num2;
      cin.ignore();

      calc.setNum1(num1);
      calc.setNum2(num2);
      calc.division();
      choice = 'c';
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