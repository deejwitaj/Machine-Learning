#ifndef INC_99AA0F72D4BD4FCD964CFF05C3ED8DEA
#define INC_99AA0F72D4BD4FCD964CFF05C3ED8DEA

using namespace std;

#include <fstream>

class FileReader
{
public:
  FileReader();
  FileReader(ifstream m_curFile);

  bool OpenFile(std::string i_fileName);
  void CloseFile();
  std::string const GetNextWord();
  bool bHasNewLine();

private:
  ifstream m_curFile;

};
#endif
