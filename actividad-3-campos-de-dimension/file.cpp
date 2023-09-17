#include "file.h"

File::File()
{
}

void File::writeToFile(Student st)
{
  ofstream writeFile;
  stringstream ss;
  int strLen, intValue;

  writeFile.open(FILE_NAME, ios::binary | ios::app);

  if (writeFile.good())
  {
    // Write code
    intValue = st.getCode();
    writeFile.write((char *)&intValue, sizeof(int));

    ss << intValue;

    // Write name
    strLen = st.getName().length();
    writeFile.write((char *)&strLen, sizeof(int));
    writeFile.write(st.getName().c_str(), strLen * sizeof(char));

    ss << strLen << st.getName().c_str();

    // Write LastName
    strLen = st.getLastName().length();
    writeFile.write((char *)&strLen, sizeof(int));
    writeFile.write(st.getLastName().c_str(), strLen * sizeof(char));

    ss << strLen << st.getLastName().c_str();

    // Write semester
    intValue = st.getSemester();
    writeFile.write((char *)&intValue, sizeof(int));

    ss << intValue;

    // Write GeneralAverage
    intValue = st.getGeneralAverage();
    writeFile.write((char *)&intValue, sizeof(int));

    ss << intValue;
  }
  else
  {
    cout << "Error al escribir en el archivo..." << endl;
  }

  writeFile.close();
}

list<Student> File::loadAllStudents()
{
  ifstream readFile(FILE_NAME, ios::binary | ios::app);

  list<Student> studentsList;
  Student student;
  int fieldLen;

  if (readFile.good() && !isEmpty())
  {
    while (!readFile.eof())
    {
      int code, semester, generalAverage;
      string name, lastName;

      // Read code
      readFile.read((char *)&code, sizeof(int));

      // Read name
      readFile.read((char *)&fieldLen, sizeof(int));
      char auxName[fieldLen + 1];
      readFile.read((char *)auxName, fieldLen * sizeof(char));
      auxName[fieldLen] = EMPTY;
      name = auxName;

      // Read last name
      readFile.read((char *)&fieldLen, sizeof(int));
      char auxLastName[fieldLen + 1];
      readFile.read((char *)auxLastName, fieldLen * sizeof(char));
      auxLastName[fieldLen] = EMPTY;
      lastName = auxLastName;

      // Read semester
      readFile.read((char *)&semester, sizeof(int));

      // Read general average
      readFile.read((char *)&generalAverage, sizeof(int));

      if (readFile.eof())
        break;

      student = Student(code, name, lastName, semester, generalAverage);
      studentsList.push_back(student);
    }
  }
  else
  {
    cout << "Archivo no encontrado..." << endl;
  }

  readFile.close();
  return studentsList;
}

Student *File::findStudent(int codeToSearch)
{
  ifstream readFile(FILE_NAME, ios::binary | ios::app);

  Student *student;
  int fieldLen;

  if (readFile.good() && !isEmpty())
  {
    while (!readFile.eof())
    {
      int code, semester, generalAverage;
      string name, lastName;

      // Read code
      readFile.read((char *)&code, sizeof(int));

      // Read name
      readFile.read((char *)&fieldLen, sizeof(int));
      char auxName[fieldLen + 1];
      readFile.read((char *)auxName, fieldLen * sizeof(char));
      auxName[fieldLen] = EMPTY;
      name = auxName;

      // Read last name
      readFile.read((char *)&fieldLen, sizeof(int));
      char auxLastName[fieldLen + 1];
      readFile.read((char *)auxLastName, fieldLen * sizeof(char));
      auxLastName[fieldLen] = EMPTY;
      lastName = auxLastName;

      // Read semester
      readFile.read((char *)&semester, sizeof(int));

      // Read general average
      readFile.read((char *)&generalAverage, sizeof(int));

      if (readFile.eof())
        break;

      if (codeToSearch == code)
      {
        student = new Student(code, name, lastName, semester, generalAverage);
        readFile.close();
        return student;
      }
    }
  }
  else
  {
    cout << "Archivo no encontrado..." << endl;
  }

  readFile.close();
  return nullptr;
}

void File::updateStudent(Student *st)
{
  ifstream readFile(FILE_NAME, ios::binary | ios::app);

  Student *student;
  int fieldLen;

  if (readFile.good() && !isEmpty())
  {
    while (!readFile.eof())
    {
      int code, semester, generalAverage;
      string name, lastName;

      // Read code
      readFile.read((char *)&code, sizeof(int));

      // Read name
      readFile.read((char *)&fieldLen, sizeof(int));
      char auxName[fieldLen + 1];
      readFile.read((char *)auxName, fieldLen * sizeof(char));
      auxName[fieldLen] = EMPTY;
      name = auxName;

      // Read last name
      readFile.read((char *)&fieldLen, sizeof(int));
      char auxLastName[fieldLen + 1];
      readFile.read((char *)auxLastName, fieldLen * sizeof(char));
      auxLastName[fieldLen] = EMPTY;
      lastName = auxLastName;

      // Read semester
      readFile.read((char *)&semester, sizeof(int));

      // Read general average
      readFile.read((char *)&generalAverage, sizeof(int));

      if (readFile.eof())
        break;

      if (st->getCode() != code)
      {
        student = new Student(code, name, lastName, semester, generalAverage);
        writeToTempFile(*student);
      }
    }

    // Write updated student
    writeToTempFile(*st);
  }
  else
  {
    cout << "Archivo no encontrado..." << endl;
  }

  readFile.close();

  remove(FILE_NAME);
  rename(TEMP_FILE_NAME, FILE_NAME);
}

void File::writeToTempFile(Student st)
{
  ofstream writeFile;
  stringstream ss;
  int strLen, intValue;

  writeFile.open(TEMP_FILE_NAME, ios::binary | ios::app);

  if (writeFile.good())
  {
    // Write code
    intValue = st.getCode();
    writeFile.write((char *)&intValue, sizeof(int));

    ss << intValue;

    // Write name
    strLen = st.getName().length();
    writeFile.write((char *)&strLen, sizeof(int));
    writeFile.write(st.getName().c_str(), strLen * sizeof(char));

    ss << strLen << st.getName().c_str();

    // Write LastName
    strLen = st.getLastName().length();
    writeFile.write((char *)&strLen, sizeof(int));
    writeFile.write(st.getLastName().c_str(), strLen * sizeof(char));

    ss << strLen << st.getLastName().c_str();

    // Write semester
    intValue = st.getSemester();
    writeFile.write((char *)&intValue, sizeof(int));

    ss << intValue;

    // Write GeneralAverage
    intValue = st.getGeneralAverage();
    writeFile.write((char *)&intValue, sizeof(int));

    ss << intValue;
  }
  else
  {
    cout << "Error al escribir en el archivo..." << endl;
  }

  writeFile.close();
}

void File::deleteStudent(Student *st)
{
  ifstream readFile(FILE_NAME, ios::binary | ios::app);

  Student *student;
  int fieldLen;

  if (readFile.good() && !isEmpty())
  {
    while (!readFile.eof())
    {
      int code, semester, generalAverage;
      string name, lastName;

      // Read code
      readFile.read((char *)&code, sizeof(int));

      // Read name
      readFile.read((char *)&fieldLen, sizeof(int));
      char auxName[fieldLen + 1];
      readFile.read((char *)auxName, fieldLen * sizeof(char));
      auxName[fieldLen] = EMPTY;
      name = auxName;

      // Read last name
      readFile.read((char *)&fieldLen, sizeof(int));
      char auxLastName[fieldLen + 1];
      readFile.read((char *)auxLastName, fieldLen * sizeof(char));
      auxLastName[fieldLen] = EMPTY;
      lastName = auxLastName;

      // Read semester
      readFile.read((char *)&semester, sizeof(int));

      // Read general average
      readFile.read((char *)&generalAverage, sizeof(int));

      if (readFile.eof())
        break;

      if (st->getCode() != code)
      {
        student = new Student(code, name, lastName, semester, generalAverage);
        writeToTempFile(*student);
      }
    }
  }
  else
  {
    cout << "Archivo no encontrado..." << endl;
  }

  readFile.close();

  remove(FILE_NAME);
  rename(TEMP_FILE_NAME, FILE_NAME);
}

bool File::isEmpty()
{
  ifstream readFile(FILE_NAME);
  return readFile.peek() == std::ifstream::traits_type::eof();
}