#include "Interface.h"
#include "FileReader.h"

#include <iostream>
#include <sstream>

using namespace::std;

void Interface::Init()
{
  FileReader m_fileReader;

  m_fileReader.OpenFile(GetVocabFile());
  while (m_fileReader.bHasNewLine())
    cout << m_fileReader.GetNextWord();
}

void Interface::pause()
{
  std::cin.get();
}

std::string Interface::GetVocabFile()
{
  std::string input = "";

  cout << "What is the path of the vocabulary file I will be using?\n";
  getline(cin, input);
  return input;
}

int main() 
{
  Interface m_interface;
  m_interface.Init();

  return 0;
}