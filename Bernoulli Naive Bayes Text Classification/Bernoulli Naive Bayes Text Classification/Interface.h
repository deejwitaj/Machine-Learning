#ifndef INC_D397E7B2F63D4E0FA8A982D68622D81E
#define INC_D397E7B2F63D4E0FA8A982D68622D81E

#include "FileReader.h"
#include "DirectoryReader.h"
#include "Agent.h"

#include <list>

class Interface
{
public:
  void Init();

private:
  Agent m_agent;
  FileReader m_fileReader;
  DirectoryReader m_directoryReader;
  std::list<std::string> m_classifiers;

  void pause();

  std::list<std::string> GetDirectoryOfFiles();
  std::string GetInput();

  bool AskYesOrNo();
  void InitializeVocabulary();
  void TrainClassifier();
};
#endif

