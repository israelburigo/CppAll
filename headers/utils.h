#ifndef UTILS_H
#define UTILS_H

#include <windows.h>
#include <string.h>
#include <iostream>
#include <SDL2/SDL.h>

using namespace std; 


/**
 * \brief Método que chama OpneFileDialog do windows
 * \param filter filtro passado ao componente do windows
 */
string openfilename(char *filter = "All Files (*.*)\0*.*\0") {
  OPENFILENAME ofn;
  char fileName[MAX_PATH] = "";
  ZeroMemory(&ofn, sizeof(ofn));

  ofn.lStructSize = sizeof(OPENFILENAME);
  ofn.lpstrFilter = filter;
  ofn.lpstrFile = fileName;
  ofn.nMaxFile = MAX_PATH;
  ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
  ofn.lpstrDefExt = "";

  string fileNameStr;

  if ( GetOpenFileName(&ofn) )
    fileNameStr = fileName;

  return fileNameStr;
}



#endif