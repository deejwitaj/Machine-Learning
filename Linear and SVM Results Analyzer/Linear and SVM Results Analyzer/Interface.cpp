#include "Interface.h"
#include "FileReader.h"

#include <iostream>
#include <sstream>
#include <algorithm>
#include <locale>

using namespace::std;

void Interface::Init()
{
  cout << "Am I analyzing linear or SVM results?\n";
  auto result = AskThisOrThat("linear", "SVM");
  switch (result)
  {
  case 1:
    cout << "Ok, lets analyze linear\nWhere is my preprocessed testing data?\n";
    m_fileReader.OpenFile(GetInput());
    while (m_fileReader.bHasNewLine())
    {
      auto word = GetFirstWord(m_fileReader.GetNextLine());
      if ((word.compare("")))
        m_trueResults.emplace_back(stoi(word));
    }
    cout << "True results read in\n";
    m_fileReader.CloseFile();
    break;
  case 2:
    cout << "Ok, lets analyze SVM\n";
    break;
  default:
    cout << "Huh?";
  }
  pause();
}

//Returns 1 if the first choice was picked and 2 if the second choice was picked
int Interface::AskThisOrThat(std::string const first, std::string const second)
{
  auto answer = GetInput();
  if (!answer.compare(first))
    return 1;
  else if (!answer.compare(second))
    return 2;
  else
  {
    cout << "Please give a valid answer\n" + first + " or " + second + "\n";
    return AskThisOrThat(first, second);
  }
}

//Returns true if yes is enetered, and false for no
bool Interface::AskYesOrNo()
{
  return (AskThisOrThat("y", "n") == 1) ? true : false;
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

std::string Interface::GetFirstWord(std::string const line)
{
  using namespace std;

  string firstWord = "";
  char newCharacter;

  for (auto it : line)
  {
    newCharacter = it;
    if ((newCharacter >= '0' && newCharacter <= '9'))
      firstWord = firstWord + newCharacter;
    else
      return firstWord;
  }
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