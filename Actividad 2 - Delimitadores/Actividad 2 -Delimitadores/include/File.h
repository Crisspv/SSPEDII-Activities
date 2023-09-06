#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <fstream>
#include <ctime>

#include "Calculator.h"

# define FILE_NAME "calculator_registry.txt"
# define TEMP_FILE_NAME "temp.txt"
# define DELIMITER '|'
# define ENDL '\n'
# define NULL_ASCII '\0'

using namespace std;

class File
{
    public:
        File();
        ~File();
        void writeFile(Calculator calc);
        void readFromFile();
        void searchInFile(int);
        void modifyInFile(int);
        void deleteInFile(int);

        void modifyRegistry(char[], char[], char[], char[], char[], char[]);

        int getLastId();
        int getId();
        void setId(int);

    private:
        int id;
};

#endif // FILE_H
