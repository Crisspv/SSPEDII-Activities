#include "file.h"

File::File()
{
}

void File::readFromFile()
{
  ifstream readFile(FILE_NAME);

  if (!readFile.is_open())
  {
    throw bad_alloc();
  }

  Calculator calcNode;
  while (readFile >> calcNode)
  {
    calculatorList->push_back(calcNode);
  }

  readFile.close();
}

void File::writeToFile()
{
  ofstream writeFile(FILE_NAME, ios::app);

  if (!writeFile.is_open())
  {
    throw bad_alloc();
  }

  list<Calculator>::iterator it;
  for (it = calculatorList->begin(); it != calculatorList->end(); it++)
  {
    writeFile << *it;
  }

  writeFile.close();
}

void File::addToList(Calculator calc)
{
  calculatorList->push_back(calc);
}