#ifndef INC_E95E06694C614E0B8E899DEA9A1577A6
#define INC_E95E06694C614E0B8E899DEA9A1577A6

using namespace std;

#include <Windows.h>

#include <string>

class DirectoryReader
{
public:

  bool SetDirectory(std::string i_directory);
  bool bHasNextFileName();
  bool GetCurrentFileName(std::string &io_fileName);
  std::string GetCurrentDir() { return m_directoryName; }

private:

  WIN32_FIND_DATA m_fileData;
  HANDLE m_fileHandle;
  std::string m_directoryName;
};
#endif
