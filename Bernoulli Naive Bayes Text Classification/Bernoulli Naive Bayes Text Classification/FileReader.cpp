#include "FileReader.h"

#include <iostream>

//Opens file in passed in location and sets its ifstream to the first line in file
bool FileReader::OpenFile(std::string i_fileName)
{
  m_curFile.open(i_fileName);
  return !(m_curFile.fail());
}

std::string const FileReader::GetNextWord()
{
  char* newLine = "";
  if(!m_curFile.eof())
    m_curFile.getline(newLine, 256);

  return newLine;
}