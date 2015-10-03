#include "DirectoryReader.h"

#include <iostream>

bool DirectoryReader::SetDirectory(std::string i_directoryName)
{
  cout << "Setting directory.\n";

  m_directoryName = i_directoryName;

  m_fileHandle = FindFirstFile(i_directoryName.c_str(), &m_fileData);
  if (m_fileHandle == INVALID_HANDLE_VALUE)
  {
    cout << "INVALID HANDLE VALUE!\n";
    return false;
  }

  cout << "Directory successfully set.\n";
  return true;
}

bool DirectoryReader::bHasNextFileName()
{
  if (m_fileHandle != INVALID_HANDLE_VALUE)
  {
    if (!FindNextFile(m_fileHandle, &m_fileData))
    {
      FindClose(m_fileHandle);
      cout << "No next file!\n";
      return false;
    }
    //cout << "Found next file.\n";
    return true;
  }

  cout << "File handle is invalid!\n";
  return false;
}

bool DirectoryReader::GetCurrentFileName(std::string &io_fileName)
{
  if (m_fileHandle != INVALID_HANDLE_VALUE)
  {
    //cout << "File name is: " << m_fileData.cFileName << endl << endl;
    io_fileName = m_fileData.cFileName;
    return true;
  }

  cout << "There is no valid file data.\n";
  return false;
}