#include "Interface.h"
#include "FileReader.h"

#include <iostream>
#include <sstream>

using namespace::std;

void Interface::Init()
{
  InitializeVocabulary();
  BeginTraining();
  pause();
}

void Interface::BeginTraining()
{
  cout << "What is my training file?\n";
  m_fileReader.OpenFile(GetFile());
  while (m_fileReader.bHasNewLine())
  {
    cout << m_fileReader.GetNextWord() + "\n";
    pause();
  }

}
void Interface::InitializeVocabulary()
{
  cout << "What is the path of the vocabulary file I will be using?\n";
  m_fileReader.OpenFile(GetFile());
  cout << "Loading vocab file...\n";
  while (m_fileReader.bHasNewLine())
    m_agent.AddVocabWord(m_fileReader.GetNextWord());
  m_fileReader.CloseFile();
  cout << "Vocab file loaded.\n";
}

void Interface::pause()
{
  std::cin.get();
}

std::string Interface::GetDirectoryOfFiles()
{
  std::string input = "";
  return input;
}

std::string Interface::GetFile()
{
  std::string input = "";

  getline(cin, input);
  return input;
}

int main() 
{
  Interface m_interface;
  m_interface.Init();

  return 0;
}