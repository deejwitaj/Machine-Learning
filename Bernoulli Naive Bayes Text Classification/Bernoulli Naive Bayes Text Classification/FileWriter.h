#ifndef INC_9CE6B686F66C4862BEFEDD8F647FD11E
#define INC_9CE6B686F66C4862BEFEDD8F647FD11E

using namespace std;

#include <fstream>

class FileWriter
{
public:
  FileWriter();
  ~FileWriter();

  void OpenFile(std::string const &i_fileName);
  void AddLine(std::string const &i_line);
  void CloseFile();

private:
  ofstream *m_curFile;
};
#endif