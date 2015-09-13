#ifndef INC_99AA0F72D4BD4FCD964CFF05C3ED8DEA
#define INC_99AA0F72D4BD4FCD964CFF05C3ED8DEA

using namespace std;

#include <fstream>

class FileReader
{
public:
  bool OpenFile(std::string i_fileName);
  std::string const GetNextWord();

private:
  ifstream m_curFile;

};
#endif
