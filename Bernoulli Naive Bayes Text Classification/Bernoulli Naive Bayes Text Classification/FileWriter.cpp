#include "FileWriter.h"

#include <iostream>

void FileWriter::OpenFile(std::string const &i_fileName)
{
  cout << "Opening or creating file at path" << i_fileName.c_str() << endl << endl;
  m_curFile.open(i_fileName);
}

void FileWriter::CloseFile()
{
  m_curFile.close();
}

void FileWriter::AddLine(std::string const &i_line)
{
  m_curFile.write(i_line.c_str(), i_line.size());
}
