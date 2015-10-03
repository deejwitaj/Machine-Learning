#include "Interface.h"
#include "FileReader.h"

#include <iostream>
#include <sstream>

using namespace::std;

void Interface::Init()
{
  pause();
}

bool Interface::AskYesOrNo()
{
  std::string answer = GetInput();
  if (!answer.compare("y"))
    return true;
  else if (!answer.compare("n"))
    return false;
  else
  {
    cout << "Please give a valid answer\n y or n\n";
    return AskYesOrNo();
  }
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