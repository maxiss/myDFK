#pragma once

#define DllExport __declspec(dllexport)
#define DllImport __declspec(dllimport)

#ifdef GAME_EXPORT_DLL
   #define GAME_EXPORT DllExport
#else
   #define GAME_EXPORT DllImport
#endif
