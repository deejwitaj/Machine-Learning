#ifndef INC_9D518403790B46E18B9FC7A9A89DB275
#define INC_9D518403790B46E18B9FC7A9A89DB275

#include <map>
#include <string>

class Parameter
{
public:
  void insert(std::pair<int, int> i_parameter, long i_probability = 0);
  void insert(int i_vocabWord, int i_classifier, long i_probability = 0);

  float GetProbability(std::pair<int, int> i_parameter) const;
  float GetProbability(int i_vocabWord, int i_classifier) const;
  float GetInverseProbability(std::pair<int, int> i_parameter) const;
  float GetInverseProbability(int i_vocabWord, int i_classifier) const;

  void SetProbability(std::pair<int, int> i_parameter, long i_probability);
  void SetProbability(int i_vocabWord, int i_classifier, long i_probability);

private:
  std::map<std::pair<int, int>, long> m_parameters;
};

#endif
