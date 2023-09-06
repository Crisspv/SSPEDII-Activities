#include "File.h"

File::File()
{
    this->setId(getLastId());
}


File::~File()
{
    //dtor
}

void File::writeFile(Calculator calc)
{
    ofstream File(FILE_NAME, ios::app);

    const int MAXLEN = 80;
    char date[MAXLEN];
    time_t t = time(0);
    strftime(date, MAXLEN, "%m/%d/%Y", localtime(&t));

    File << getLastId() << DELIMITER << calc.getOperation() << DELIMITER << calc.getNum1()<< DELIMITER << calc.getNum2() << DELIMITER << calc.getRes() << DELIMITER << date << endl;
    File.close();
}

void File::readFromFile()
{
    ifstream File(FILE_NAME);
    char id[50];
    char operation[50];
    char num1[50];
    char num2[50];
    char res[50];
    char date[50];

    if(!File.good()) {
        cout << "El archivo no existe" <<endl;
    } else {
        int i;
        while(!File.eof()) {
            i = 0;
            do{
                File.read((char *)&id[i],1);
                if(File.eof())
                    break;
                i++;
            }while(id[i-1] != DELIMITER);
            id[i-1] = NULL_ASCII;

            i = 0;
            do{
                File.read((char *)&operation[i],1);
                if(File.eof())
                    break;
                i++;
            }while(operation[i-1] != DELIMITER);
            operation[i-1] = NULL_ASCII;

            i = 0;
            do{
                File.read((char *)&num1[i],1);
                if(File.eof())
                    break;
                i++;
            }while(num1[i-1] != DELIMITER);
            num1[i-1] = NULL_ASCII;

            i = 0;
            do{
                File.read((char *)&num2[i],1);
                if(File.eof())
                    break;
                i++;
            }while(num2[i-1] != DELIMITER);
            num2[i-1] = NULL_ASCII;

            i = 0;
            do{
                File.read((char *)&res[i],1);
                if(File.eof())
                    break;
                i++;
            }while(res[i-1] != DELIMITER);
            res[i-1] = NULL_ASCII;


            i = 0;
            do{
                File.read((char *)&date[i],1);
                if(File.eof())
                    break;
                i++;
            }while(date[i-1] != ENDL);
            date[i-1] = NULL_ASCII;

            if(File.eof())
                break;

            cout << "id:        " << id << endl;
            cout << "operacion: " << operation << endl;
            cout << "num1:      " << num1 << endl;
            cout << "num2:      " << num2 << endl;
            cout << "res:       " << res << endl;
            cout << "fecha:     " << date << endl << endl;
        }
    }
    File.close();
}

void File::searchInFile(int idToSearch)
{
    ifstream File(FILE_NAME);
    char id[50];
    char operation[50];
    char num1[50];
    char num2[50];
    char res[50];
    char date[50];
    bool found = false;

    if(!File.good()) {
        cout << "El archivo no existe" << endl;
    } else {
        int i;
        while(!File.eof()) {
            i = 0;
            do{
                File.read((char *)&id[i],1);
                if(File.eof())
                    break;
                i++;
            }while(id[i-1] != DELIMITER);
            id[i-1] = NULL_ASCII;

            i = 0;
            do{
                File.read((char *)&operation[i],1);
                if(File.eof())
                    break;
                i++;
            }while(operation[i-1] != DELIMITER);
            operation[i-1] = NULL_ASCII;

            i = 0;
            do{
                File.read((char *)&num1[i],1);
                if(File.eof())
                    break;
                i++;
            }while(num1[i-1] != DELIMITER);
            num1[i-1] = NULL_ASCII;

            i = 0;
            do{
                File.read((char *)&num2[i],1);
                if(File.eof())
                    break;
                i++;
            }while(num2[i-1] != DELIMITER);
            num2[i-1] = NULL_ASCII;

            i = 0;
            do{
                File.read((char *)&res[i],1);
                if(File.eof())
                    break;
                i++;
            }while(res[i-1] != DELIMITER);
            res[i-1] = NULL_ASCII;


            i = 0;
            do{
                File.read((char *)&date[i],1);
                if(File.eof())
                    break;
                i++;
            }while(date[i-1] != ENDL);
            date[i-1] = NULL_ASCII;

            if(File.eof())
                break;

            if(idToSearch == atoi(id)) {
                found = true;
                cout << "\nid:        " << id << endl;
                cout << "operacion: " << operation << endl;
                cout << "num1:      " << num1 << endl;
                cout << "num2:      " << num2 << endl;
                cout << "res:       " << res << endl;
                cout << "fecha:     " << date << endl << endl;
            }
        }

        if(found == false) {
            cout << "\nRegistro no encontrado..." << endl;
        }
    }
    File.close();
}

void File::modifyInFile(int idToSearch)
{
    ifstream File(FILE_NAME);
    char id[50];
    char operation[50];
    char num1[50];
    char num2[50];
    char res[50];
    char date[50];
    bool found = false;

    if(!File.good()) {
        cout << "El archivo no existe" << endl;
    } else {
        int i;

        while(!File.eof()) {
            i = 0;
            do{
                File.read((char *)&id[i],1);
                if(File.eof())
                    break;
                i++;
            }while(id[i-1] != DELIMITER);
            id[i-1] = NULL_ASCII;

            i = 0;
            do{
                File.read((char *)&operation[i],1);
                if(File.eof())
                    break;
                i++;
            }while(operation[i-1] != DELIMITER);
            operation[i-1] = NULL_ASCII;

            i = 0;
            do{
                File.read((char *)&num1[i],1);
                if(File.eof())
                    break;
                i++;
            }while(num1[i-1] != DELIMITER);
            num1[i-1] = NULL_ASCII;

            i = 0;
            do{
                File.read((char *)&num2[i],1);
                if(File.eof())
                    break;
                i++;
            }while(num2[i-1] != DELIMITER);
            num2[i-1] = NULL_ASCII;

            i = 0;
            do{
                File.read((char *)&res[i],1);
                if(File.eof())
                    break;
                i++;
            }while(res[i-1] != DELIMITER);
            res[i-1] = NULL_ASCII;


            i = 0;
            do{
                File.read((char *)&date[i],1);
                if(File.eof())
                    break;
                i++;
            }while(date[i-1] != ENDL);
            date[i-1] = NULL_ASCII;

            if(File.eof())
                break;

            if(idToSearch == atoi(id)) {
                found = true;
                modifyRegistry(id, operation, num1, num2, res, date);
            }
        }

        if(found == false) {
            cout << "\nRegistro no encontrado..." << endl;
        }
    }
    File.close();
}

void File::modifyRegistry(char* id, char* operation, char* num1, char* num2, char* res, char* date)
{
    // Resto de la lógica de modificación aquí



    char choice;
    ofstream TempFile(TEMP_FILE_NAME, ios::app);

    do {
        cout << "Ingrese la opcion que desea modificar" << endl << endl;
        cout << "1. Operacion" << endl;
        cout << "2. Num 1" << endl;
        cout << "3. Num 2" << endl;
        cout << "4. Res" << endl;
        cout << "5. Fecha" << endl;
        cout << "c. Regresar" << endl << endl;

        cout << "Opcion: ";
        cin.ignore();
        cin >> choice;

        switch(choice) {
        case '1':
            char newOperation;

            cout << "\nElije la nueva operacion" << endl << endl;
            cout << "1. Suma" << endl;
            cout << "2. Resta" << endl;
            cout << "3. Multiplicacion" << endl;
            cout << "4. Division" << endl << endl;

            cout << "Opcion: ";
            cin.ignore();
            cin >> newOperation;

            switch (newOperation) {
            case '1':
                TempFile << id << DELIMITER << newOperation << DELIMITER << calc.getNum1() << DELIMITER << calc.getNum2() << DELIMITER << calc.getRes() << DELIMITER << date << endl;
                break;

            case '2':

                break;
            default:
                cout << "Operacion invalida..." << endl;
            }
        break;
        case '2':
        break;
        case '3':
        break;
        case '4':
        break;
        case '5':
        break;
        case 'c':
        break;
        default:
            cout << "Opcion invalida..." << endl;
        }
    } while(choice != 'c');

    TempFile.close();
}


void File::deleteInFile(int)
{

}


int File::getLastId()
{
    ifstream File(FILE_NAME);

    char idArray[50];
    char operation[50];
    char num1[50];
    char num2[50];
    char res[50];
    char date[50];

    if(!File.good()) {
        return 1;
    } else {
        int i;
        while(!File.eof()) {
            i = 0;
            do{
                File.read((char *)&idArray[i],1);
                if(File.eof())
                    break;
                i++;
            }while(idArray[i-1] != DELIMITER);
            idArray[i-1] = NULL_ASCII;

            i = 0;
            do{
                File.read((char *)&operation[i],1);
                if(File.eof())
                    break;
                i++;
            }while(operation[i-1] != DELIMITER);
            operation[i-1] = NULL_ASCII;

            i = 0;
            do{
                File.read((char *)&num1[i],1);
                if(File.eof())
                    break;
                i++;
            }while(num1[i-1] != DELIMITER);
            num1[i-1] = NULL_ASCII;

            i = 0;
            do{
                File.read((char *)&num2[i],1);
                if(File.eof())
                    break;
                i++;
            }while(num2[i-1] != DELIMITER);
            num2[i-1] = NULL_ASCII;

            i = 0;
            do{
                File.read((char *)&res[i],1);
                if(File.eof())
                    break;
                i++;
            }while(res[i-1] != DELIMITER);
            res[i-1] = NULL_ASCII;


            i = 0;
            do{
                File.read((char *)&date[i],1);
                if(File.eof())
                    break;
                i++;
            }while(date[i-1] != ENDL);
            date[i-1] = NULL_ASCII;

            if(File.eof())
            break;
        }
    }
    File.close();

    int lastId = atoi(idArray);
    return lastId + 1;
}

int File::getId()
{
    return id;
}

void File::setId(int id)
{
    this->id = id;
}


