#include "Agent.h"

#include <algorithm>

#include <iostream>

Agent::Agent()
  : m_numOfDocuments(0)
{}

void Agent::AddVocabWord(std::string const &i_vocabWord)
{
  m_vocabulary.insert(std::make_pair(ConvertToLowerCase(i_vocabWord), false));
}

void Agent::AddVocabFile(std::string const &i_fileName)
{
  cout << "Loading vocab file...\n";
  m_fileReader.OpenFile(std::move(i_fileName));
  while (m_fileReader.bHasNewLine())
  {
    std::string vocabWord = m_fileReader.GetNextWord();
    if (vocabWord.compare(""))
      AddVocabWord(vocabWord);
  }
    //AddVocabWord(m_fileReader.GetNextWord());
  m_fileReader.CloseFile();
  SetVocabularyBools(false);
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
  IncrementNumOfDocuments();

  auto it = m_classifiers.find(i_parameter);
  if (it == m_classifiers.end())
    AddLearnedClassifier(i_parameter);

  m_fileReader.OpenFile(std::move(i_fileName));
  while (m_fileReader.bHasNewLine())
  {
    std::string line = ConvertToLowerCase(m_fileReader.GetNextWord());
    for (auto it : m_vocabulary)
    {
      if (!(it.second))
      {
        if (!(line.compare(it.first)))
        {
          IncrementNumOfDocumentsInClassifierWithVocabWord(it.first, i_parameter);
          it.second = true;
        }
      }
    }
  }

  SetVocabularyBools(false);
  IncrememntDocumentsInClassifier(i_parameter);
  m_fileReader.CloseFile();
}

std::string Agent::ConvertToLowerCase(std::string const &i_line)
{
  std::string ret = i_line;
  std::transform(ret.begin(), ret.end(), ret.begin(), ::tolower);
  return ret;
}

size_t Agent::GetNumOfLearnedClassifiers()
{
  return m_classifiers.size();
}

void Agent::IncrementNumOfDocuments()
{
  m_numOfDocuments++;
}

void Agent::AddLearnedClassifier(std::string const &i_classifierName)
{
  m_classifiers.insert(i_classifierName);
}

void Agent::IncrememntDocumentsInClassifier(std::string const &i_classifierName)
{
  auto it = m_numOfDocumentsInEachClassifier.find(i_classifierName);
  if (it != m_numOfDocumentsInEachClassifier.end())
    it->second = it->second++;

  else
    m_numOfDocumentsInEachClassifier.insert(std::make_pair(i_classifierName, 1));
}

void Agent::IncrementNumOfDocumentsInClassifierWithVocabWord(std::string const &i_vocabWord, std::string const &i_classifier)
{
  auto it = m_parameterJC.find(std::make_pair(i_vocabWord, i_classifier));
  if (it == m_parameterJC.end())
    m_parameterJC.insert(std::make_pair(std::make_pair(i_vocabWord, i_classifier), 1));
  else
    it->second++;
}

void Agent::SetVocabularyBools(bool b)
{
  for (auto it : m_vocabulary)
    it.second = b;
}

void Agent::PrintResults()
{
  m_fileWriter.OpenFile("Results.txt");
  for (auto const it : m_classifiers)
  {
    m_fileWriter.AddLine("I haved read " + std::to_string(m_numOfDocuments) + " documents.\n");
    float Nc = m_numOfDocumentsInEachClassifier.find(it)->second;
    float fraction = (Nc + 1) / (m_numOfDocuments + GetNumOfLearnedClassifiers());
    m_fileWriter.AddLine("The fraction of documents that belong to the  " + it + " classifier is: " + std::to_string(fraction) + "\n");
  }
  m_fileWriter.CloseFile();

  m_fileWriter.OpenFile("Parameters.txt");
  for (auto const it : m_parameterJC)
  {
    m_fileWriter.AddLine(it.first.first);
    m_fileWriter.AddLine(it.first.second);
    m_fileWriter.AddLine(std::to_string(it.second));
  }
  m_fileWriter.CloseFile();
}
