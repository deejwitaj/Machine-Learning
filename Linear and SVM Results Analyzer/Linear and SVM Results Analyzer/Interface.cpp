#include "Interface.h"
#include "FileReader.h"

#include <iostream>
#include <sstream>
#include <algorithm>
#include <locale>

using namespace::std;

void Interface::Init()
{
  cout << "Am I analyzing linear or SVM results?\n";
  auto result = AskThisOrThat("linear", "SVM");
  double macroFScore = 0;
  switch (result)
  {
  case 1:
    cout << "Ok, lets analyze linear\nWhere is my preprocessed testing data?\n";
    m_fileReader.OpenFile(GetInput());
    StoreTrueResults();
    m_fileReader.CloseFile();
    cout << "And where are my predicted results?\n";
    m_fileReader.OpenFile(GetInput());
    StorePredictedResults();
    m_fileReader.CloseFile();
    CreateConfusionMatrix();
    cout << "Where would you like me to place the scores?";
    m_fileWriter.OpenFile(GetInput());
    for (auto it : m_confusionMatrix)
    {
      double precision = CalculatePrecision(it.first, it.second);
      double recall = CalculateRecall(it.first, it.second);
      double fScore = CalculateFScore(precision, recall);
      macroFScore += fScore;
      m_fileWriter.AddLine("The precision for classification " + std::to_string(it.first) + " is " + std::to_string(precision) + "\n");
      m_fileWriter.AddLine("The recall for classification " + std::to_string(it.first) + " is " + std::to_string(recall) + "\n");
      m_fileWriter.AddLine("The F1 Score for classification " + std::to_string(it.first) + " is " + std::to_string(fScore) + "\n");
    }
    m_fileWriter.AddLine("The Macro-F1 score across all categories is " + std::to_string(macroFScore / 20.0) + "\n");
    m_fileWriter.CloseFile();
    break;
  case 2:
    cout << "Ok, lets analyze SVM\n";
    break;
  default:
    cout << "Huh?";
  }
  pause();
}

//Stores the actual classifications of each file from a preprocessed data file that m_fileReader currently has open
void Interface::StoreTrueResults()
{
  while (m_fileReader.bHasNewLine())
  {
    auto word = GetFirstWord(m_fileReader.GetNextLine());
    //For some reason, the last line is a blank line. So we check for this to avoid attempting to stoi a blank line
    if ((word.compare("")))
      m_trueResults.emplace_back(stoi(word));
  }
  cout << "True results read in\n";
}

void Interface::StorePredictedResults()
{
  while (m_fileReader.bHasNewLine())
  {
    auto digit = m_fileReader.GetNextLine();
    //For some reason, the last line is a blank line. So we check for this to avoid attempting to stoi a blank line
    if ((digit.compare("")))
      m_predictedResults.emplace_back(stoi(digit));
  }
  cout << "Predicted results read in\n";
}
//Returns 1 if the first choice was picked and 2 if the second choice was picked
int Interface::AskThisOrThat(std::string const first, std::string const second)
{
  auto answer = GetInput();
  if (!answer.compare(first))
    return 1;
  else if (!answer.compare(second))
    return 2;
  else
  {
    cout << "Please give a valid answer\n" + first + " or " + second + "\n";
    return AskThisOrThat(first, second);
  }
}

//Returns true if yes is enetered, and false for no
bool Interface::AskYesOrNo()
{
  return (AskThisOrThat("y", "n") == 1) ? true : false;
}

void Interface::pause()
{
  std::cin.get();
}

double Interface::CalculateFScore(double i_precision, double i_recall)
{
  if ((i_precision + i_recall) == 0)
    return 0;

  return ((2 * i_precision*i_recall) / (i_precision + i_recall));
}

double Interface::CalculatePrecision(int i_classifier, confusionMatrix i_confusionMatrix)
{
  auto it = m_confusionMatrix.find(i_classifier);
  if (it != m_confusionMatrix.end())
  {
    double truePositive = it->second.truePositive;
    double falsePositive = it->second.falsePositive;

    if ((falsePositive + truePositive) == 0)
      return 0;

    return (truePositive / (falsePositive + truePositive));
  }

  return 0;
}

double Interface::CalculateRecall(int i_classifier, confusionMatrix i_confusionMatrix)
{
  auto it = m_confusionMatrix.find(i_classifier);
  if (it != m_confusionMatrix.end())
  {
    double truePositive = it->second.truePositive;
    double falseNegative = it->second.falseNegative;

    if ((truePositive + falseNegative) == 0)
      return 0;

    return (truePositive / (truePositive + falseNegative));
  }

  return 0;
}
void Interface::CreateConfusionMatrix()
{
  for (int i = 1; i <= 20; i++)
  {
    m_confusionMatrix.insert(std::make_pair(i, confusionMatrix()));
  }

  auto trueIt = m_trueResults.begin();
  auto predictedIt = m_predictedResults.begin();
  while ((trueIt != m_trueResults.end()) && (predictedIt != m_predictedResults.end()))
  {
    /*If the values match in predicted and true, then it means we have both found a true positive for the current classifier
      and a true negative for all other classifiers*/
    if (*trueIt == *predictedIt)
    {
      auto it = m_confusionMatrix.find(*trueIt);
      if (it != m_confusionMatrix.end())
      {
        it->second.truePositive += 1;
        for (auto& innerit : m_confusionMatrix)
        {
          if (innerit.first != *trueIt)
            innerit.second.trueNegative += 1;
        }
      }
    }

    /*If the values do not match, then we have both a false negative for the current trueIt value and a false positive for the current
      predictedIt value*/
    else
    {
      auto innerTrueIt = m_confusionMatrix.find(*trueIt);
      if (innerTrueIt != m_confusionMatrix.end())
        innerTrueIt->second.falseNegative += 1;
      auto innerPredIt = m_confusionMatrix.find(*predictedIt);
      if (innerPredIt != m_confusionMatrix.end())
        innerPredIt->second.falsePositive += 1;
    }

    trueIt++;
    predictedIt++;
  }
}

std::list<std::string> Interface::GetDirectoryOfFiles()
{
  std::list<std::string> ret;
  ret.insert(ret.end(), GetInput());
  cout << "Are there any more classifiers to train on?\ny or n\n";

  while (AskYesOrNo())
  {
    cout << "What is the classifier?\n";
    ret.insert(ret.end(), GetInput());
    cout << "Are there any more classifiers to train on?\ny or n\n";
  }

  return ret;
}

std::string Interface::GetFirstWord(std::string const line)
{
  using namespace std;

  string firstWord = "";
  char newCharacter;

  for (auto it : line)
  {
    newCharacter = it;
    if ((newCharacter >= '0' && newCharacter <= '9'))
      firstWord = firstWord + newCharacter;
    else
      return firstWord;
  }

  return firstWord;
}

std::string Interface::GetInput()
{
  std::string input = "";

  getline(cin, input);
  return input;
}

int main()
{
  Interface m_interface;
  m_interface.Init();

  return 0;
}