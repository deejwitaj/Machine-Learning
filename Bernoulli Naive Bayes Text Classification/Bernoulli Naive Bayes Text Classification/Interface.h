#ifndef INC_D397E7B2F63D4E0FA8A982D68622D81E
#define INC_D397E7B2F63D4E0FA8A982D68622D81E

#include "FileReader.h"
#include "Agent.h"

class Interface
{
public:
  void Init();

private:
  Agent m_agent;
  FileReader m_fileReader;

  void pause();

  std::string GetDirectoryOfFiles();
  std::string GetInput();
  void InitializeVocabulary();
  void BeginTraining();
};
#endif

