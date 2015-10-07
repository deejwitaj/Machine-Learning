#pragma once
#ifndef INC_7F2B6F6E9358421680143AEF070E0E30
#define INC_7F2B6F6E9358421680143AEF070E0E30

#include "FileReader.h"
#include "FileWriter.h"

#include <list>
#include <map>

class Interface
{
public:
  void Init();

private:
  struct confusionMatrix
  {
  public:
    int truePositive = 0;
    int trueNegative = 0;
    int falsePositive = 0;
    int falseNegative = 0;
  };

  FileReader m_fileReader;
  FileWriter m_fileWriter;
  std::list<int> m_trueResults;
  std::list<int> m_predictedResults;
  std::map<int, confusionMatrix> m_confusionMatrix;

  void pause();

  double CalculateFScore(double i_precision, double i_recall);
  double CalculatePrecision(int i_classifier, confusionMatrix i_confusionMatrix);
  double CalculateRecall(int i_classifier, confusionMatrix i_confusionMatrix);
  void CreateConfusionMatrix();

  std::list<std::string> GetDirectoryOfFiles();
  std::string GetFirstWord(std::string const line);
  std::string GetInput();

  void StorePredictedResults();
  void StoreTrueResults();

  int AskThisOrThat(std::string const first, std::string const second);
  bool AskYesOrNo();
};
#endif

