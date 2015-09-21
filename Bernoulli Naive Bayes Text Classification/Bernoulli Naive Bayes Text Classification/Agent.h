#ifndef INC_0DE44E66A97D42A9BF01F22B6ECECA37
#define INC_0DE44E66A97D42A9BF01F22B6ECECA37

#include "Parameter.h"
#include "FileReader.h"
#include "DirectoryReader.h"

#include <set>

enum STATE
{
  TRAINING,
  TESTING
};

class Agent
{
public:
  void AddVocabWord(std::string const &i_vocabWord);
  
  void BeginTraining();
  void BeginTesting();

private:
  Parameter m_parameters;
  std::set<std::string> m_vocabulary;
  STATE m_state;
};
#endif
