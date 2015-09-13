#include "Interface.h"

#include <iostream>
#include <sstream>

using namespace::std;


void pause()
{
  std::cin.get();
}

void getVocabFile()
{
  std::string input = "";

  cout << "What is the path of the vocabulary file I will be using?\n";
  getline(cin, input);
  cout << "Opening file at path " << input << endl << endl;
}

int main() 
{
  pause();

  return 0;
}