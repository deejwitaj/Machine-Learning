#include "Interface.h"
#include "FileReader.h"

#include <iostream>
#include <sstream>

using namespace::std;

void Interface::Init()
{
  InitializeVocabulary();
  TrainClassifier();
  pause();
}

void Interface::TrainClassifier()
{
  cout << "What are my training classifier?\n";
  m_classifiers = GetDirectoryOfFiles();
  for (auto it : m_classifiers)
  {
    m_directoryReader.SetDirectory(it + "\\*.txt");
  
    std::string nextFileName = "";

    do {
      std::string fileName = "";
      m_directoryReader.GetCurrentFileName(fileName);
      m_agent.TrainOnFile(it + "\\" + fileName, it);
    } while (m_directoryReader.bHasNextFileName());
  }
  //std::string classifier = GetInput();

  /*cout << "Are there any more classifiers I should train on?\nPlease type either y or n\n";
  if (AskYesOrNo())
    TrainClassifier();

  else*/
    m_agent.PrintResults();

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

std::list<std::string> Interface::GetDirectoryOfFiles()
{
  std::list<std::string> ret;
  ret.insert(ret.end(), GetInput());
  cout << "Are there any more classifiers to train on?\ny or n\n";

  while (AskYesOrNo())
  {
    cout << "What is the classifier?\n";
    ret.insert(ret.end(), GetInput());
    cout << "Are there any more classifiers to train on?\ny or n\n";
  }

  return ret;
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