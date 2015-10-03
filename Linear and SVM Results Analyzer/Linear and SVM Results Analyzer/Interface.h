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
  std::list<std::string> m_classifiers;

  void pause();

  std::list<std::string> GetDirectoryOfFiles();
  std::string GetInput();

  bool AskYesOrNo();
};
#endif

