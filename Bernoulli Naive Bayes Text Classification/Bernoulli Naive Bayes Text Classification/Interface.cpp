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
  cout << "What is my next training classifier?\n";
  m_directoryReader.SetDirectory(GetInput());
  
  std::string nextFileName = "";

  do {
    std::string fileName = "";
    m_directoryReader.GetCurrentFileName(fileName);
  } while (m_directoryReader.bHasNextFileName());

  cout << "Are there any more classifiers I should train on?\nPlease type either y or n\n";
  if (AskYesOrNo())
    BeginTraining();

}

bool Interface::AskYesOrNo()
{
  std::string answer = GetInput();
  if (!answer.compare("y"))
    return true;
  else if(!answer.compare("n"))
    return false;
  else
  {
    cout << "Please give a valid answer\n y or n\n";
    return AskYesOrNo();
  }
}
void Interface::InitializeVocabulary()
{
  cout << "What is the path of the vocabulary file I will be using?\n";
  m_agent.AddVocabFile(GetInput());
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

std::string Interface::GetInput()
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