#include "Parameter.h"

void Parameter::insert(std::pair<int, int> i_parameter, long probability)
{
  m_parameters.insert(std::make_pair(i_parameter, probability));
}

void Parameter::insert(int i_vocabWord, int i_classifier, long i_probability)
{
  insert(std::make_pair(i_vocabWord, i_classifier), i_probability);
}

float Parameter::GetProbability(std::pair<int, int> i_parameter) const
{
  auto it = m_parameters.find(i_parameter);
  if (it == m_parameters.end())
    return 0;

  return m_parameters.find(i_parameter)->second;
}

float Parameter::GetProbability(int i_vocabWord, int i_classifier) const
{
  return GetProbability(std::make_pair(i_vocabWord, i_classifier));
}

float Parameter::GetInverseProbability(std::pair<int, int> i_parameter) const
{
  return (1 - GetProbability(i_parameter));
}

float Parameter::GetInverseProbability(int i_vocabWord, int i_classifier) const
{
  return GetInverseProbability(std::make_pair(i_vocabWord, i_classifier));
}

void Parameter::SetProbability(std::pair<int, int> i_parameter, long i_probability)
{
  auto it = m_parameters.find(i_parameter);
  if (it != m_parameters.end())
    it->second = i_probability;
  else
    insert(i_parameter, i_probability);
}

void Parameter::SetProbability(int i_vocabWord, int i_parameter, long i_probability)
{
  SetProbability(std::make_pair(i_vocabWord, i_parameter), i_probability);
}