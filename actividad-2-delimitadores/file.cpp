#include "file.h"

File::File()
{
}

list<Calculator> File::readFromFile()
{
  ifstream readFile(FILE_NAME);
  list<Calculator> calcList;

  if (!readFile.good())
  {
    cout << "Problemas con el archivo..." << endl;
  }
  else
  {
    Calculator auxCalc;

    while (readFile >> auxCalc)
    {
      calcList.push_back(auxCalc);
    }
  }

  readFile.close();
  return calcList;
}

void File::writeToFile(Calculator calc)
{
  ofstream writeFile(FILE_NAME, ios::app);

  if (!writeFile.good())
  {
    cout << "Problemas con el archivo..." << endl;
  }
  else
  {
    writeFile << calc;
  }

  writeFile.close();
}

void File::writeListToTempFile(list<Calculator> calcList)
{
  ofstream writeFile(TEMP_FILE_NAME, ios::app);

  if (!writeFile.good())
  {
    cout << "Problemas con el archivo..." << endl;
  }
  else
  {
    list<Calculator>::iterator it;
    for (it = calcList.begin(); it != calcList.end(); ++it)
    {
      writeFile << *it;
    }
  }

  writeFile.close();
}

int File::getLastId()
{
  ifstream readFile(FILE_NAME);

  if (!readFile.good())
  {
    return 0;
  }
  else
  {
    list<Calculator> calcList;

    calcList = readFromFile();
    return calcList.back().getId();
  }
}