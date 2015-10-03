#ifndef INC_0DE44E66A97D42A9BF01F22B6ECECA37
#define INC_0DE44E66A97D42A9BF01F22B6ECECA37

using namespace std;

#include "Parameter.h"
#include "FileReader.h"
#include "FileWriter.h"

#include <set>
#include <list>
#include <vector>
#include <map>

#include <fstream>

enum STATE
{
  TRAINING,
  TESTING
};

class Agent
{
public:
  Agent();

  void AddVocabWord(std::string const &i_vocabWord);
  void AddVocabFile(std::string const &i_fileName);
  
  void BeginTraining();
  void BeginTesting();

  void TrainOnFile(std::string const &i_fileName, std::string const &i_parameter);
  std::string ConvertToLowerCase(std::string const &i_line);

  void PrintResults();

  size_t GetNumOfLearnedClassifiers();

private:
  FileReader m_fileReader;
  FileWriter m_fileWriter;
  Parameter m_parameters;
  std::map<std::string, bool> m_vocabulary;
  std::set<std::string> m_classifiers;
  std::map<std::pair<std::string, std::string>, int> m_parameterJC; //First is vocab word, second is parameter, third is the number of parameter documents with word
  int m_numOfDocuments;
  std::map<std::string, int> m_numOfDocumentsInEachClassifier;
  STATE m_state;

  void AddLearnedClassifier(std::string const &i_classifierName);
  void IncrementNumOfDocuments();
  void IncrememntDocumentsInClassifier(std::string const &i_classifier);
  void IncrementNumOfDocumentsInClassifierWithVocabWord(std::string const &i_vocabWord, std::string const &classifier);
  void SetVocabularyBools(bool b);
};
#endif
