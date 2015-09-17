#include "FileReader.h"

#include <iostream>

std::string VOCABFILE = "vocabularies.txt";
//"C:\\Users\\Didier\\Google Drive\\Grad School\\CAP 5610 - Machine Learning\\Homework\\Assignment 1\\vocabularies.txt";

FileReader::FileReader()
  : m_curFile(nullptr)
{
}

//Opens file in passed in location and sets its ifstream to the first line in file
bool FileReader::OpenFile(std::string i_fileName)
{
  cout << "Opening file at path " << VOCABFILE.c_str() << endl << endl;
  m_curFile = new ifstream(VOCABFILE);

  if (m_curFile->is_open())
  {
    cout << "File opened successfully!";
    return true;
  }
  
  cout << "Opening file failed";
  return false;
}

std::string const FileReader::GetNextWord()
{
  char* newLine = "";
  if(!m_curFile->eof())
    m_curFile->getline(newLine, 256);

  return newLine;
}

bool FileReader::bHasNewLine()
{
  return !m_curFile->eof();
}