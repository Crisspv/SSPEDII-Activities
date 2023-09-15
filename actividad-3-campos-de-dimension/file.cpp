#include "file.h"

File::File()
{
}

list<Student> File::readFromFile()
{
  ifstream readFile(FILE_NAME);
  list<Student> studentList;

  if (!readFile.good())
  {
    cout << "Problemas con el archivo..." << endl;
  }
  else
  {
    Student auxStudent;

    while (readFile >> auxStudent)
    {
      studentList.push_back(auxStudent);
    }
  }

  readFile.close();
  return studentList;
}

void File::writeToFile(Student st)
{
  ofstream writeFile(FILE_NAME, ios::app);

  if (!writeFile.good())
  {
    cout << "Problemas con el archivo..." << endl;
  }
  else
  {
    writeFile << st;
  }

  writeFile.close();
}

void File::writeListToTempFile(list<Student> stList)
{
  ofstream writeFile(TEMP_FILE_NAME, ios::app);

  if (!writeFile.good())
  {
    cout << "Problemas con el archivo..." << endl;
  }
  else
  {
    list<Student>::iterator it;
    for (it = stList.begin(); it != stList.end(); ++it)
    {
      // writeFile << *it;
    }
  }

  writeFile.close();

  remove(FILE_NAME);
  rename(TEMP_FILE_NAME, FILE_NAME);
}

bool File::isCodeExisting(int code)
{
  list<Student> stList = readFromFile();
  list<Student>::iterator it;

  for (it = stList.begin(); it != stList.end(); ++it)
  {
    if (code == it->getCode())
    {
      return true;
    }
  }

  return false;
}