#include "FileReader.h"

#include <iostream>
#include <string>

std::string VOCABFILE = "vocabularies.txt";
//"C:\\Users\\Didier\\Google Drive\\Grad School\\CAP 5610 - Machine Learning\\Homework\\Assignment 1\\vocabularies.txt";

FileReader::FileReader()
{
}

//Opens file in passed in location and sets its ifstream to the first line in file
bool FileReader::OpenFile(std::string i_fileName)
{
  cout << "Opening file at path " << i_fileName.c_str() << endl << endl;
  m_curFile.open(VOCABFILE);

  if (m_curFile.is_open())
  {
    cout << "File opened successfully!\n\n";
    return true;
  }
  
  cout << "Opening file failed\n\n";
  return false;
}

void FileReader::CloseFile()
{
  m_curFile.close();
}

std::string const FileReader::GetNextWord()
{
  using namespace std;

  string newLine;
  if(!m_curFile.eof())
    getline(m_curFile, newLine);

  return newLine;
}

bool FileReader::bHasNewLine()
{
  return !m_curFile.eof();
}