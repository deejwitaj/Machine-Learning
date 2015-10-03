#pragma once
#ifndef INC_7F2B6F6E9358421680143AEF070E0E30
#define INC_7F2B6F6E9358421680143AEF070E0E30

#include "FileReader.h"
#include "DirectoryReader.h"

#include <list>

class Interface
{
public:
  void Init();

private:
  FileReader m_fileReader;
  DirectoryReader m_directoryReader;
  std::list<int> m_trueResults;
  std::list<int> m_predictedResults;

  void pause();

  std::list<std::string> GetDirectoryOfFiles();
  std::string GetFirstWord(std::string const line);
  std::string GetInput();

  int AskThisOrThat(std::string const first, std::string const second);
  bool AskYesOrNo();
};
#endif

