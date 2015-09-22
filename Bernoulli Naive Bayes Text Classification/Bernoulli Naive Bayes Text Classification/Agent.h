#ifndef INC_0DE44E66A97D42A9BF01F22B6ECECA37
#define INC_0DE44E66A97D42A9BF01F22B6ECECA37

using namespace std;

#include "Parameter.h"
#include "FileReader.h"

#include <set>
#include <list>

#include <fstream>

enum STATE
{
  TRAINING,
  TESTING
};

class Agent
{
public:
  void AddVocabWord(std::string const &i_vocabWord);
  void AddVocabFile(std::string const &i_fileName);
  
  void BeginTraining();
  void BeginTesting();

  void TrainOnFile(ifstream *i_fileStream, std::string const &i_parameter);
  std::string ConvertToLowerCase(std::string const &i_line);

private:
  FileReader m_fileReader;
  Parameter m_parameters;
  std::set<std::string> m_vocabulary;
  STATE m_state;
};
#endif
