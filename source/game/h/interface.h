#pragma once

#define DllExport __declspec(dllexport)
#define DllImport __declspec(dllimport)

#ifdef EXPORTS
   #define DLLEXPORT DllExport
#else
   #define DLLEXPORT DllImport
#endif

extern "C"
{
   DLLEXPORT void startGame();
}
