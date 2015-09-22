#include "FileWriter.h"

#include <iostream>

FileWriter::FileWriter()
  : m_curFile(nullptr)
{
}

FileWriter::~FileWriter()
{
  delete m_curFile;
}

void FileWriter::OpenFile(std::string const &i_fileName)
{
  if (m_curFile)
    delete m_curFile;

  cout << "Opening or creating file at path" << i_fileName.c_str() << endl << endl;
  m_curFile->open(i_fileName);
}

void FileWriter::CloseFile()
{
  m_curFile->close();
  delete m_curFile;
}

void FileWriter::AddLine(std::string const &i_line)
{
  if (m_curFile)
    m_curFile->write(i_line.c_str(), i_line.size());
}
