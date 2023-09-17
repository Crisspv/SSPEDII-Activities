#include "file.h"

File::File()
{
}

void File::writeToFile(Student st)
{
  ofstream writeFile(FILE_NAME, ios::binary | ios::app);
  stringstream ss;

  int strLen, intValue;

  if (!writeFile.good())
  {
    cout << "Problemas con el archivo..." << endl;
  }
  else
  {
    // Write code
    intValue = st.getCode();
    writeFile.write((char *)&intValue, sizeof(int));

    ss << intValue;

    // Write Name
    strLen = st.getName().length();
    writeFile.write((char *)&strLen, sizeof(int));
    writeFile.write(st.getName().c_str(), strLen * sizeof(char));

    ss << strLen << st.getName().c_str();

    // Write LastName
    strLen = st.getLastName().length();
    writeFile.write((char *)&strLen, sizeof(int));
    writeFile.write(st.getLastName().c_str(), strLen * sizeof(char));

    ss << strLen << st.getLastName().c_str();

    // Write Semester
    intValue = st.getSemester();
    writeFile.write((char *)&intValue, sizeof(int));

    ss << intValue;

    // Write GeneralAverage
    intValue = st.getGeneralAverage();
    writeFile.write((char *)&intValue, sizeof(int));

    ss << intValue;
  }

  writeFile.close();
}

list<Student> File::loadAllStudents()
{
  ifstream readFile(FILE_NAME, ios::binary | ios::app);

  Student student;
  list<Student> studentsList;
  int fieldLen;

  if (!readFile.good())
  {
  }
  else
  {
    readFile.read((char *)&fieldLen, sizeof(int));
    while (!readFile.eof())
    {
      int code, semester, generalAverage;
      string name, lastName;

      // Read Code
      readFile.read((char *)&code, sizeof(int));

      cout << "code" << code << endl;

      // Read Name
      readFile.read((char *)&fieldLen, sizeof(char));
      char auxName[fieldLen + 1];
      readFile.read((char *)auxName, fieldLen * sizeof(char));
      auxName[fieldLen] = EMPTY;
      name = auxName;

      // Read LastName
      readFile.read((char *)&fieldLen, sizeof(int));
      char auxLastName[fieldLen + 1];
      readFile.read((char *)auxLastName, fieldLen * sizeof(char));
      auxLastName[fieldLen] = EMPTY;
      lastName = auxLastName;

      // Read Semester
      readFile.read((char *)&semester, sizeof(int));

      // Read GeneralAverage
      readFile.read((char *)&generalAverage, sizeof(int));

      student = Student(code, name, lastName, semester, generalAverage);
      studentsList.push_back(student);
    }
  }

  readFile.close();
  return studentsList;
}

Student *File::findStudent(int codeToSearch)
{
  ifstream readFile(FILE_NAME, ios::binary | ios::app);

  Student *existingStudent;
  int fieldLen;

  if (!readFile.good())
  {
    return nullptr;
  }
  else
  {
    readFile.read((char *)&fieldLen, sizeof(int));
    while (!readFile.eof())
    {
      int code, semester, generalAverage;
      string name, lastName;

      // Read Code
      readFile.read((char *)&code, sizeof(int));

      // Read Name
      readFile.read((char *)&fieldLen, sizeof(char));
      char auxName[fieldLen + 1];
      readFile.read((char *)auxName, fieldLen * sizeof(char));
      auxName[fieldLen] = EMPTY;
      name = auxName;

      // Read LastName
      readFile.read((char *)&fieldLen, sizeof(int));
      char auxLastName[fieldLen + 1];
      readFile.read((char *)auxLastName, fieldLen * sizeof(char));
      auxLastName[fieldLen] = EMPTY;
      lastName = auxLastName;

      // Read Semester
      readFile.read((char *)&semester, sizeof(int));

      // Read GeneralAverage
      readFile.read((char *)&generalAverage, sizeof(int));

      if (codeToSearch == code)
      {
        existingStudent = new Student(code, name, lastName, semester, generalAverage);
        readFile.close();
        return existingStudent;
      }
    }
  }

  readFile.close();
  return nullptr;
}