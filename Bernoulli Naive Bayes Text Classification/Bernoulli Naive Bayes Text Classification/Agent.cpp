#include "Agent.h"

#include <algorithm>

#include <iostream>

void Agent::AddVocabWord(std::string const &i_vocabWord)
{
  m_vocabulary.insert(ConvertToLowerCase(i_vocabWord));
}

void Agent::AddVocabFile(std::string const &i_fileName)
{
  m_fileReader.OpenFile(std::move(i_fileName));
  while (m_fileReader.bHasNewLine())
    AddVocabWord(m_fileReader.GetNextWord());
  m_fileReader.CloseFile();
  cout << "Vocab file loaded.\n";
}

void Agent::BeginTraining()
{
  m_state = TRAINING;
}

void Agent::BeginTesting()
{
  m_state = TESTING;
}

void Agent::TrainOnFile(std::string const &i_fileName, std::string const &i_parameter)
{
}

std::string Agent::ConvertToLowerCase(std::string const &i_line)
{
  std::string ret = i_line;
  std::transform(ret.begin(), ret.end(), ret.begin(), ::tolower);
  return ret;
}
