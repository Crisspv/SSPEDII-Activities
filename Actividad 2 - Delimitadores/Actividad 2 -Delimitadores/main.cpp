#include <iostream>
#include <cstdlib>

#include "Calculator.h"
#include "File.h"

using namespace std;

void cleanScreen() {
    system("cls");
}

void pauseScreen() {
    system("pause");
}

void cleanBuffer() {
    cin.ignore();
    fflush(stdin);
}

void calcMenu()
{
    char choice;

    int num1 = 0;
    int num2 = 0;

    Calculator calc;
    File file;

    do {
        cleanScreen();
        cout << "MENU CALCULADORA" << endl << endl;

        cout << "Elije la opcion deseada:" <<endl;
        cout << "1. Sumar" << endl;
        cout << "2. Restar" << endl;
        cout << "3. Multiplicar" << endl;
        cout << "4. Dividir" << endl;
        cout << "c. Regresar" << endl << endl;

        cout << "Opcion: ";
        cin.ignore();
        cin >> choice;

        switch(choice) {
        case '1':
            cleanScreen();

            cout << "Ingrese num 1: ";
            cin.ignore();
            cin >> num1;

            cout << "Ingrese num 2: ";
            cin.ignore();
            cin >> num2;

            calc.setNum1(num1);
            calc.setNum2(num2);
            calc.sum(num1, num2);
            calc.setOperation("suma");
            file.writeFile(calc);

            cout << "Resultado de la suma es: " << calc.getRes() <<endl;
            pauseScreen();
            break;
        case '2':
            cleanScreen();

            cout << "Ingrese num 1: ";
            cin.ignore();
            cin >> num1;

            cout << "Ingrese num 2: ";
            cin.ignore();
            cin >> num2;

            calc.setNum1(num1);
            calc.setNum2(num2);
            calc.sub(num1, num2);
            calc.setOperation("resta");
            file.writeFile(calc);

            cout << "Resultado de la resta es: " << calc.getRes() <<endl;
            pauseScreen();
            break;
        case '3':
            cleanScreen();

            cout << "Ingrese num 1: ";
            cin.ignore();
            cin >> num1;

            cout << "Ingrese num 2: ";
            cin.ignore();
            cin >> num2;

            calc.setNum1(num1);
            calc.setNum2(num2);
            calc.mult(num1, num2);
            calc.setOperation("multiplicacion");
            file.writeFile(calc);

            cout << "Resultado de la multiplicacion es: " << calc.getRes() <<endl;
            pauseScreen();
            break;
        case '4':
            cleanScreen();

            cout << "Ingrese num 1: ";
            cin.ignore();
            cin >> num1;

            cout << "Ingrese num 2: ";
            cin.ignore();
            cin >> num2;

            calc.setNum1(num1);
            calc.setNum2(num2);
            calc.div(num1, num2);
            calc.setOperation("division");
            file.writeFile(calc);

            cout << "Resultado de la division es: " << calc.getRes() <<endl;
            pauseScreen();
            break;
        case'c':
            break;

        default:
            cout << "Opcion invalida..." << endl;
            pauseScreen();
            cleanBuffer();
        }
    } while(choice != 'c');
}

void fileMenu() {
    char choice;
    int id;

    Calculator calc;
    File file;

    do {
        cleanScreen();
        cout << "MENU ARCHIVO" << endl << endl;

        cout << "Elije la opcion deseada:" <<endl;
        cout << "1. Agregar" << endl;
        cout << "2. Mostrar" << endl;
        cout << "3. Buscar" << endl;
        cout << "4. Modificar" << endl;
        cout << "5. Eliminar" << endl;
        cout << "c. Regresar" << endl << endl;

        cout << "Opcion: ";
        cin.ignore();
        cin >> choice;

        switch(choice) {
        case '1'://agregar

            break;

        case '2'://mostrar
            cleanScreen();
            cout << "Todos los registros" << endl << endl;
            file.readFromFile();
            pauseScreen();
            break;

        case '3':
            cleanScreen();//buscar
            cout << "Ingrese el id a buscar: ";
            cin.ignore();
            cin >> id;

            file.searchInFile(id);
            pauseScreen();
            break;

        case '4'://modificar
            cleanScreen();

            cout << "Ingrese el id del registro que desea modificar: ";
            cin.ignore();
            cin >> id;

            file.modifyInFile(id);
            break;
        case '5'://eliminar
            cleanScreen();
            cout << "Ingrese el id de la operacion que desea eliminar: ";
            break;
        case 'c':
            break;
        default:
            cout << "opcion invalida..." << endl;
            pauseScreen();
            cleanBuffer();
        }
    } while(choice != 'c');
}

int main()
{
    char choice;

    do {
        cleanScreen();
        cout << "Actividad 2 - Delimitadores" << endl <<endl;

        cout << "Elije la opcion deseada:" <<endl;
        cout << "1. Calculadora" << endl;
        cout << "2. Archivos" << endl;
        cout << "c. Salir" << endl <<endl;

        cout << "Opcion: ";

        cin >> choice;

        switch(choice) {
        case '1':
            calcMenu();
            break;

        case '2':
            fileMenu();
            break;

        case 'c':
            break;

        default:
            cout << "Opcion incorrecta..." << endl;
            pauseScreen();
            cleanBuffer();
        }
    } while(choice != 'c');

    return 0;
}
