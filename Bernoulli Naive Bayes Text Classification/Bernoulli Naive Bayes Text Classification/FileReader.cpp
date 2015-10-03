#include "FileReader.h"

#include <iostream>
#include <string>

FileReader::FileReader()
{
}

//Opens file in passed in location and sets its ifstream to the first line in file
bool FileReader::OpenFile(std::string i_fileName)
{
  //cout << "Opening file at path " << i_fileName.c_str() << endl << endl;
  m_curFile.open(i_fileName);

  if (m_curFile.is_open())
  {
    //cout << "File opened successfully!\n\n";
    return true;
  }
  
  cout << "Opening file failed\n\n";
  return false;
}

void FileReader::CloseFile()
{
  m_curFile.close();
}

std::string const FileReader::GetNextLine()
{
  using namespace std;

  string newLine;
  if (!m_curFile.eof())
    getline(m_curFile, newLine);

  return newLine;
}

std::string const FileReader::GetNextWord()
{
  using namespace std;

  string newWord = "";
  char newCharacter;

  while (!m_curFile.eof())
  {
    newCharacter = m_curFile.get();
    if ((newCharacter >= 'A' && newCharacter <= 'Z') || (newCharacter >= 'a' && newCharacter <= 'z'))
    {
      newWord = newWord + newCharacter;
    }
    else if (newWord.compare(""))
      return newWord;
  }
    //getline(m_curFile, newLine);

  return "";
}

bool FileReader::bHasNewLine()
{
  return !m_curFile.eof();
}