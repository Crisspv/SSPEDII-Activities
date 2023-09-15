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
  cout << endl;
  cout << "Presione <enter> para continuar..." << endl;
  getchar();
}

void Menu::mainMenu()
{
  char choice;
  int code, semester, search;
  string name, lastName;
  float generalAverage;
  bool isFound = false;

  Student myStudent;
  File myFile;

  list<Student> studentsList;
  list<Student>::iterator it;

  do
  {
    cls();
    cout << "ACTIVIDAD 3" << endl
         << endl;
    cout << "1. Insertar Alumno" << endl;
    cout << "2. Mostar Alumnos" << endl;
    cout << "3. Buscar Alumno" << endl;
    cout << "4. Modificar Alumno" << endl;
    cout << "5. Eliminar Alumno" << endl;
    cout << "c. Salir" << endl
         << endl;

    cout << "Opcion: ";
    cin >> choice;
    cin.ignore();

    switch (choice)
    {
    case '1':
      cout << endl;
      cout << "Codigo: ";
      cin >> code;
      cin.ignore();

      cout << "Nombre: ";
      getline(cin, name);

      cout << "Apellido: ";
      getline(cin, lastName);

      cout << "Semestre: ";
      cin >> semester;

      cout << "Promedio general: ";
      cin >> generalAverage;
      cin.ignore();

      if (!myFile.isCodeExisting(code))
      {
        myStudent.setCode(code);
        myStudent.setName(name);
        myStudent.setLastName(lastName);
        myStudent.setSemester(semester);
        myStudent.setGeneralAverage(generalAverage);
        myFile.writeToFile(myStudent);
        cout << "Registro guardado con exito..." << endl;
      }
      else
      {
        cout << "Codigo existente, registro no ingresado..." << endl;
      }
      enterToContinue();
      break;

    case '2':
      studentsList = myFile.readFromFile();
      for (it = studentsList.begin(); it != studentsList.end(); ++it)
      {
        printStudent(*it);
      }
      enterToContinue();
      break;

    case '3':
      cout << endl;
      cout << "Ingresa el codigo a buscar: ";
      cin >> search;
      cin.ignore();

      studentsList = myFile.readFromFile();
      for (it = studentsList.begin(); it != studentsList.end(); ++it)
      {
        if (search == it->getCode())
        {
          isFound = true;
          printStudent(*it);
          enterToContinue();
          break;
        }
      }

      if (!isFound)
      {
        cout << "Registro no encontrado" << endl;
        enterToContinue();
      }
      break;

    case '4':
      cout << endl;
      cout << "Ingresa el codigo a modificar: ";
      cin >> search;
      cin.ignore();

      studentsList = myFile.readFromFile();
      for (it = studentsList.begin(); it != studentsList.end(); ++it)
      {
        if (search == it->getCode())
        {
          isFound = true;
          modifyStudent(*it);
          enterToContinue();
          break;
        }
      }

      if (!isFound)
      {
        cout << "Registro no encontrado" << endl;
        enterToContinue();
      }
      else
      {
        myFile.writeListToTempFile(studentsList);
        cout << "Registro modificado exitosamente..." << endl;
        enterToContinue();
      }
      break;

    case '5':
      cout << endl;
      cout << "Ingresa el codigo a eliminar: ";
      cin >> search;
      cin.ignore();

      studentsList = myFile.readFromFile();
      for (it = studentsList.begin(); it != studentsList.end(); ++it)
      {
        if (search == it->getCode())
        {
          isFound = true;
          cout << "Registro encontrado!" << endl;
          printStudent(*it);
          it = studentsList.erase(it);
          enterToContinue();
          break;
        }
        else
        {
          it++;
        }
      }

      if (!isFound)
      {
        cout << "Registro no encontrado" << endl;
        enterToContinue();
      }
      else
      {
        myFile.writeListToTempFile(studentsList);
        cout << "Registro eliminado con exito..." << endl;
        enterToContinue();
      }
      break;

    case 'c':
      break;

    default:
      cout << "Opcion incorrecta..." << endl;
      enterToContinue();
      break;
    }
  } while (choice != 'c');
}

void Menu::modifyStudent(Student &student)
{
  int code, semester;
  string name, lastName;
  float generalAverage;

  cout << endl;
  cout << "Codigo: ";
  cin >> code;
  cin.ignore();

  cout << "Nombre: ";
  getline(cin, name);

  cout << "Apellido: ";
  getline(cin, lastName);

  cout << "Semestre: ";
  cin >> semester;

  cout << "Promedio general: ";
  cin >> generalAverage;
  cin.ignore();

  student.setCode(code);
  student.setName(name);
  student.setLastName(lastName);
  student.setSemester(semester);
  student.setGeneralAverage(generalAverage);
}

void Menu::printStudent(Student st)
{
  cout << endl;
  cout << "Codigo:           " << st.getCode() << endl;
  cout << "Nombre:           " << st.getName() << endl;
  cout << "Apellido:         " << st.getLastName() << endl;
  cout << "Semestre:         " << st.getSemester() << endl;
  cout << "Promedio General: " << st.getGeneralAverage() << endl
       << endl;
}