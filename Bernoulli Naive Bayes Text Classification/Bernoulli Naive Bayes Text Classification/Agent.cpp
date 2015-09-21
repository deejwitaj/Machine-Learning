#include "Agent.h"

void Agent::AddVocabWord(std::string const &i_vocabWord)
{
  m_vocabulary.insert(i_vocabWord);
}

void Agent::BeginTraining()
{
  m_state = TRAINING;
}

void Agent::BeginTesting()
{
  m_state = TESTING;
}
